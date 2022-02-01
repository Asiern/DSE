/*
 Funciones relacionadas con el modulo CN: inicializacion del modulo
 y rutina de atencion.

Egileak: Izaskun
Data: Febrero 2020
*/

#include "p24HJ256GP610A.h"
#include "commons.h"

// Funcion para inicializar el modulo CN
//==================
void inic_CN()
{
	CNEN2bits.CN16IE = 1; // habilitacion de la interrupcion del pin CN16
						  // que es al que esta conectado el pulsador S6
	IEC1bits.CNIE = 1;	  // habilitacion de la interrupcion general de CN
	IFS1bits.CNIF = 0;	  // Puesta a 0 del flag IF del modulo
}

// RUTINA DE ATENCION A LA INTERRUPCION DE CN
//==============================
void _ISR_NO_PSV _CNInterrupt()
{
	if (!PORTDbits.RD7)
	{
		LATAbits.LATA4 = !LATAbits.LATA4; // kommutatu D7 LEDaren egoera
	}
	IFS1bits.CNIF = 0;
}
