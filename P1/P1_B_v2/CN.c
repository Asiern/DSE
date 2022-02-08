#include "p24HJ256GP610A.h"
#include "commons.h"

// Funcion para inicializar el modulo CN
//==================

/**
 * @brief Inicializar módulo CN y habilitar las interrupciones de los pulsadores S4, S5 y S6.
 * @return (void)
 */
void inic_CN()
{
    CNEN2bits.CN16IE = 1; // Habilitacion de la interrupcion del pin CN16 => Pulsador S6
    CNEN2bits.CN19IE = 1; // Habilitacion de la interrupcion del pin CN19 => Pulsador S4
    CNEN2bits.CN23IE = 1; // Habilitacion de la interrupcion del pin CN23 => Pulsador S5

    IEC1bits.CNIE = 1; // habilitacion de la interrupcion general de CN
    IFS1bits.CNIF = 0; // Puesta a 0 del flag IF del modulo
}

// RUTINA DE ATENCION A LA INTERRUPCION DE CN
//==============================

/**
 * @brief Rutina de atención de las interrupciones de los pulsadores.
 * @return (void)
 */
void _ISR_NO_PSV _CNInterrupt()
{
    Nop();
    Nop();
    Nop();

    if (!PORTAbits.RA7) // S5
        LATAbits.LATA2 = !LATAbits.LATA2;

    if (!PORTDbits.RD13) // S4
        LATAbits.LATA0 = !LATAbits.LATA0;

    if (!PORTDbits.RD7) // S6
        LATAbits.LATA4 = !LATAbits.LATA4;

    IFS1bits.CNIF = 0; // Apagar el flag de petición de interrupción
}
