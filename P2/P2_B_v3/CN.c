#include "CN.h"
#include "p24HJ256GP610A.h"
#include "commons.h"
#include "globals.h"

void init_CN()
{
    CNEN2bits.CN16IE = 1; // Habilitar interrupciones del pulsador S6
    IEC1bits.CNIE = 1;    // Habilitar interrupciones del módulo CN
    IFS1bits.CNIF = 0;    // Apagar flag de interrupcion del módulo CN
}

void _ISR_NO_PSV _CNInterrupt()
{

    if (!PORTDbits.RD7) // Comprobar si el pulsador S6 ha sido pulsado
    {
        IEC3bits.T7IE = !IEC3bits.T7IE; // Deshabilitar interrupciones del Temporizador T7
        flag = 0;
    }
    IFS1bits.CNIF = 0; // Apagar el flag de petición de interrupción
}