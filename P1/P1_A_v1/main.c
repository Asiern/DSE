/*
 * File:   main_P1_A_v1.c
 * Author:
 *
 * Created on
 */

#include "p24HJ256GP610A.h"

main(void)
{
    // inicializaciones de los pines como entrada o salida
    // 1= IN (entrada); 0= OUT (salida)
    // leds en el puerto A: RA7-RA0. El resto como entrada

    TRISA = 0xFF00;
    // Pulsadores en el puerto D
    TRISDbits.TRISD6 = 1;  // S3
    TRISDbits.TRISD7 = 1;  // S6
    TRISDbits.TRISD13 = 1; // S4

    // El pin RA7 es especial ya que tiene conectados el pulsador S5 y el led D10

    TRISAbits.TRISA7 = 1;

    // bucle principal
    while (1)
    {
        while (!PORTDbits.RD6)
        {
            Nop();
            Nop();
            LATAbits.LATA0 = 1;
            Nop();
            Nop();
        }
        LATAbits.LATA0 = 0;
        LATAbits.LATA2 = 1;
        LATAbits.LATA2 = 0;
        LATAbits.LATA2 = 1;
        LATAbits.LATA2 = 0;
    }
}
