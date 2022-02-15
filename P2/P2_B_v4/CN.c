#include "CN.h"
#include "p24HJ256GP610A.h"
#include "commons.h"
#include "globals.h"

void init_CN()
{
    CNEN2bits.CN16IE = 1; // Habilitar interrupciones del pulsador S6
    CNEN2bits.CN19IE = 1; // Habilitar interrupciones del pulsador S4
    IEC1bits.CNIE = 1;    // Habilitar interrupciones del módulo CN
    IFS1bits.CNIF = 0;    // Apagar flag de interrupcion del módulo CN
}

void _ISR_NO_PSV _CNInterrupt()
{

    if (!PORTDbits.RD7) // Comprobar si el pulsador S6 ha sido pulsado
    {
        T7CONbits.TON = !T7CONbits.TON; // Deshabilitar interrupciones del Temporizador T7
        flag = 0;
    }
    if (!PORTDbits.RD13) // Comprobar si el pulsador S4 ha sido pulsado
    {
        flag = 0;
        reset = 1;
        TMR7 = 0;
    }
    IFS1bits.CNIF = 0; // Apagar el flag de petición de interrupción
}