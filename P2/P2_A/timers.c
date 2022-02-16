#include "p24HJ256GP610A.h"
#include "commons.h"

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
    T7CONbits.TGATE = 0; // Deshabilitar el modo Gate
    T7CONbits.TON = 1;   // puesta en marcha del temporizador
}

void inic_crono(unsigned int *mili, unsigned int *deci,
                unsigned int *seg, unsigned int *min)
// inicializacion de las variables del cronometro
{
    *mili = 0;
    *deci = 0;
    *seg = 0;
    *min = 0;
}

void delay_10ms() // detecta que el timer ha llegado a 10 milisegundos
{
    // Completad el codigo
    while (IFS3bits.T7IF == 0) // encuesta continua
        Nop();

    IFS3bits.T7IF = 0;
}

void cronometro(unsigned int *mili, unsigned int *deci,
                unsigned int *seg, unsigned int *min) // control del tiempo mediante el temporizador 7
{
    delay_10ms(); // espera a que pasen 10 milisegundos
                  // actualiza las variables del cronometro adecuadamente
    // Completad el codigo
    (*mili) += 10;
    if ((*mili) == 100)
    {
        (*mili) = 0;
        (*deci)++;
        LATAbits.LATA7 = !LATAbits.LATA7;
    }
    if ((*deci) == 10)
    {
        (*deci) = 0;
        (*seg)++;
        LATAbits.LATA6 = !LATAbits.LATA6;
    }
    if ((*seg) == 60)
    {
        (*seg) = 0;
        (*min)++;
    }
}
