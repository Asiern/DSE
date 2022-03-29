/*
Funciones de inicializacion y tratamiento de pulsadores y leds

Egileak: Izaskun
Data: Febrero 2020
*/

#include "p24HJ256GP610A.h"
#include "commons.h"

void inic_leds()
{
  TRISA = 0xff00; // Definir como salidas los 8 pines conectados a leds: RA7-RA0
                  // El resto como entradas: 1 = In; 0 = Out
  Nop();
  Nop();
  LATA = LATA & 0xff00; // Apagar los leds
}

void inic_pulsadores()
{
  // Definir pines AN16 - AN31 como pines digitales para evitar problemas
  AD1PCFGH = 0xffff;

  TRISDbits.TRISD6 = 1;  // Definir los pines del pulsador S3 como entrada
  TRISDbits.TRISD13 = 1; // Definir los pines del pulsador S4 como entrada
  TRISAbits.TRISA7 = 1;  // Definir los pines del pulsador S5 como entrada
  TRISDbits.TRISD7 = 1;  // Definir los pines del pulsador S6 como entrada
}
