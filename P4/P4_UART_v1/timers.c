#include "p24HJ256GP610A.h"
#include "commons.h"
#include "utilidades.h"
#include "LCD.h"
#include "memoria.h"

// Globals
#include "globals.h"
unsigned int mili, deci, seg, min, reset;

void Delay_ms(int delay)
{
    if (delay > 100)
        while (1)
            ;
    TMR9 = 0;
    PR9 = 25000 - 1;
    T9CONbits.TCKPS = 0;
    T9CONbits.TCS = 0;
    T9CONbits.TON = 1;

    // Encuesta
    while (TMR9 < (delay * 20))
    {
        Nop();
    }

    // Apagar timer
    T9CONbits.TON = 0;
}

void Delay_us(int delay)
{
    TMR9 = 0;
    PR9 = 25000 - 1;
    T9CONbits.TCKPS = 1;
    T9CONbits.TCS = 0;
    T9CONbits.TON = 1;

    // Encuesta
    while (TMR9 < (delay * 2000 / 8))
    {
        Nop();
    }

    // Apagar timer
    T9CONbits.TON = 0;
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
        line_2();
        puts_lcd(Ventana_LCD[1], 16);
    }

    if (flag)
    {

        mili += 10;
        if (mili == 100)
        {
            mili = 0;
            deci++;
            LATAbits.LATA7 = !LATAbits.LATA7;
            unsigned char c[2];
            conversion_tiempo(&c, deci);
            Ventana_LCD[1][13] = c[1];
            line_2();
            puts_lcd(Ventana_LCD[1], 16);
        }
        if (deci == 10)
        {
            deci = 0;
            seg++;
            LATAbits.LATA6 = !LATAbits.LATA6;
            conversion_tiempo(&(Ventana_LCD[1][10]), seg == 60 ? 0 : seg);
            line_2();
            puts_lcd(Ventana_LCD[1], 16);
        }
        if (seg == 60)
        {
            seg = 0;
            min++;
            conversion_tiempo(&(Ventana_LCD[1][7]), min);
            line_2();
            puts_lcd(Ventana_LCD[1], 16);
        }

        flag = 0;
    }
}
