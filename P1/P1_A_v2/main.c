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

    TRISAbits.TRISA7 = 0;

    // Inicialmente encerder los leds
    LATAbits.LATA1 = 1; // D4
    LATAbits.LATA3 = 1; // D6
    LATAbits.LATA5 = 1; // D8
    LATAbits.LATA7 = 1; // D10

    // Pasar pin RA7 de analogico a digital
    AD1PCFGH = 0xFFFF;

    // bucle principal
    while (1)
    {
        // Cambiar puerto 7 a entrada
        TRISAbits.TRISA7 = 1;
        Nop();
        Nop();

        // Minetras este pulsado alguno de los pulsadores S4 S5 S6 S3
        while (!PORTDbits.RD13 || !PORTAbits.RA7 || !PORTDbits.RD7 || !PORTDbits.RD6)
        {
            if (!PORTDbits.RD6) // S3
            {
                LATAbits.LATA7 = 0; // D10
                LATAbits.LATA6 = 1; // D9
            }
            if (!PORTDbits.RD13) // S4
            {
                LATAbits.LATA1 = 0; // D4
                LATAbits.LATA0 = 1; // D3
            }
            if (!PORTAbits.RA7) // S5
            {
                TRISAbits.TRISA7 = 0;
                Nop();
                Nop();
                LATAbits.LATA3 = 0; // D6
                LATAbits.LATA2 = 1; // D5
            }
            if (!PORTDbits.RD7) // S6
            {
                LATAbits.LATA5 = 0; // D8
                LATAbits.LATA4 = 1; // D7
            }
        }
        LATAbits.LATA0 = 0; // D3
        LATAbits.LATA1 = 1; // D4
        LATAbits.LATA2 = 0; // D5
        LATAbits.LATA3 = 1; // D6
        LATAbits.LATA4 = 0; // D7
        LATAbits.LATA5 = 1; // D8
        LATAbits.LATA6 = 0; // D9
        LATAbits.LATA7 = 1; // D10
        Nop();
        Nop();
        Nop();
        Nop();
    }
}
