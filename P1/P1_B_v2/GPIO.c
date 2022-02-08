#include "p24HJ256GP610A.h"

void inic_pulsadores()
{
    // Definir pines AN16 - AN31 como pines digitales para evitar problemas
    AD1PCFGH = 0xffff;

    TRISDbits.TRISD13 = 1; // Definir los pines del pulsador S4 como entrada
    TRISAbits.TRISA7 = 1;  // Definir los pines del pulsador S5 como entrada
    TRISDbits.TRISD7 = 1;  // Definir los pines del pulsador S6 como entrada
}

void inic_leds()
{
    // Definir los 8 pines del puerto A conectados a leds (RA7-RA0) como salidas
    // El reso como entradas: 1 = In; 0 = Out
    TRISA = 0xff00;

    // Encender led D9
    LATAbits.LATA6 = 1;
}