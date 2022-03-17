#include "p24HJ256GP610A.h"
#include "commons.h"
#include "utilidades.h"
#include "LCD.h"
#include "memoria.h"

// Globals
#include "globals.h"
unsigned int mili, deci, seg, min, reset, flag;

// Estados utilizados en la rutina de atencion del T5
enum
{
    L1, // Estado de escritura en la linea1
    L2, // Estado de escritura en la linea2
    HOME1,
    HOME2,
} estadoLCD = HOME1; // Estado inicial L1

int LPos = 0; // Posicion del caracter a enviar a la ventanaLCD

void Delay_ms(int delay)
{
    TMR9 = 0;            // Inicializar registro contador
    T9CONbits.TCKPS = 0; // preescaler	1:1

    if (delay > 2)
    {
        T9CONbits.TCKPS = 1; // preescaler	1:8
        PR9 = delay * (125000 / 8);
    }

    T9CONbits.TCS = 0;
    T9CONbits.TGATE = 0; // Apagar modo gate
    T9CONbits.TON = 1;   // Encender temporizador

    // Esperar a que pase el tiempo
    while (IFS3bits.T9IF == 0)
        ;

    IFS3bits.T9IF = 0; // Apagar flag de interrupcion

    // Apagar timer
    T9CONbits.TON = 0;
}

void Delay_us(int delay)
{
    TMR9 = 0;            // Inicializar registro contador
    T9CONbits.TCKPS = 1; // preescaler	1:8
    T9CONbits.TCS = 0;
    T9CONbits.TON = 1;

    PR9 = (delay * 2000 / 8);

    // Esperar a que pase el tiempo
    while (IFS3bits.T9IF == 0)
        ;

    IFS3bits.T9IF = 0; // Apagar flag de interrupcion

    // Apagar timer
    T9CONbits.TON = 0;
}

// Interrumpir cada 1ms
void inic_Timer3()
{
    TMR3 = 0;
    PR3 = 20000 - 1;
    T3CONbits.TCKPS = 0;
    T3CONbits.TCS = 0;
    T3CONbits.TGATE = 0;
    T3CONbits.TON = 1;
    IEC0bits.T3IE = 1;
    IFS0bits.T3IF = 0;
}

// Interrumpir cada 2.5ms
void inic_Timer5()
{
    TMR5 = 0;
    PR5 = 50000 - 1;
    T5CONbits.TCKPS = 0;
    T5CONbits.TCS = 0;
    IEC1bits.T5IE = 1;
    T5CONbits.TGATE = 0;
    T5CONbits.TON = 1;
    IFS1bits.T5IF = 0;
}

void inic_Timer7()
{

    TMR7 = 0;            // Inicializar el registro de cuenta
    PR7 = 25000 - 1;     // Periodo del temporizador
                         // Queremos que cuente 10 ms.
                         // Fosc= 40 MHz (vease Inic_oscilator()) de modo que
                         // Fcy = 20 MHz (cada instruccion dos ciclos de reloj)
                         // Por tanto, Tcy= 50 ns para ejecutar una instruccion
                         // Para contar 10 ms se necesitan 200000 ciclos.
    T7CONbits.TCKPS = 1; // escala del prescaler
    T7CONbits.TCS = 0;   // reloj interno
    IFS3bits.T7IF = 0;
    IEC3bits.T7IE = 1;   // habilitar interrupciones del temporizador t7
    T7CONbits.TGATE = 0; // Deshabilitar el modo Gate
    T7CONbits.TON = 1;   // puesta en marcha del temporizador
}

void inic_crono()
// inicializacion de las variables del cronometro
{
    mili = 0;
    deci = 0;
    seg = 0;
    min = 0;
}

void cronometro() // control del tiempo mediante el temporizador 7
{
    if (reset) // Resetear cronómetro
    {
        mili = 0;
        deci = 0;
        seg = 0;
        min = 0;
        reset = 0;
        LATAbits.LATA6 = 0;
        LATAbits.LATA7 = 0;
        copiar_FLASH_RAM(Mens_LCD_6, 1);
    }

    if (flag)
    {
        mili += 10;
        if (mili == 100)
        {
            mili = 0;
            deci++;
            LATAbits.LATA7 = !LATAbits.LATA7;
            if (deci == 10)
            {
                deci = 0;
                seg++;
                LATAbits.LATA6 = !LATAbits.LATA6;
                if (seg == 60)
                {
                    seg = 0;
                    min++;
                    conversion_tiempo(&(Ventana_LCD[1][7]), min);
                }
                conversion_tiempo(&(Ventana_LCD[1][10]), seg == 60 ? 0 : seg);
            }
            unsigned char c[2];
            conversion_tiempo(&(c[0]), deci);
            Ventana_LCD[1][13] = c[1];
        }
        flag = 0;
    }
}

// Rutina de atencion a las interrupciones del T7
void _ISR_NO_PSV _T7Interrupt()
{
    flag = 1;
    IFS3bits.T7IF = 0; // Apagar el flag de petición de interrupción
}

// Rutina de atencion a las interrupciones del T3
void _ISR_NO_PSV _T3Interrupt()
{
    AD1CON1bits.SAMP = 1; // Habilitar muestreo
    IFS0bits.T3IF = 0;    // Apagar el flag de petición de interrupción
}

/**
 * Funcion para atender a las interrupciones del T5
 *
 * Mediante una máquina de estados (con los estados definidos en el enum llamado estadoLCD),
 * gestionamos el envio de caracteres a la pantalla LCD.
 *
 * En los estados L1 y L2, escribimos en su línea correspondiente
 * Mediante el estado HOME1, movemos el cursor al principio de la línea 1
 * Mediante el estado HOME2, movemos el cursor al principio de la línea 2
 *
 * Se utiliza la variable LPos para indicar la posición en la que está escribiendo
 */
void _ISR_NO_PSV _T5Interrupt()
{
    switch (estadoLCD)
    {
    case HOME1:
        lcd_cmd(0x80);
        estadoLCD = L1;
        break;
    case HOME2:
        lcd_cmd(0xC0);
        estadoLCD = L2;
        break;
    case L1:
        lcd_data(Ventana_LCD[0][LPos]);
        if (LPos == 15)
        {
            estadoLCD = HOME2;
            LPos = 0;
        }
        else
            LPos++;
        break;
    case L2:
        lcd_data(Ventana_LCD[1][LPos]);
        if (LPos == 15)
        {
            estadoLCD = HOME1;
            LPos = 0;
        }
        else
            LPos++;
        break;
    default:
        break;
    }
    IFS1bits.T5IF = 0; // Apagar flag de interrupciones
}