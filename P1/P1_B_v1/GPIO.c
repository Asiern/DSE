/*
Funciones de inicializacion y tratamiento de pulsadores y leds

Egileak: Izaskun
Data: Febrero 2020
*/

#include "p24HJ256GP610A.h"

void inic_pulsadores()
{
	// Definir pines AN16 - AN31 como pines digitales para evitar problemas
	AD1PCFGH = 0xffff;
	/* Bastaria con definir como digital el pin AN23 que es el que corresponde
 a RA7 (S5 y D10): AD1PCFGH = 0b 0000 0000 1000 0000 = 0x0080
 Si se deja como pin analogico da problemas, ya que detecta que
 el pulsador S5 esta siempre pulsado aunque no sea asi
 */

	// Definir los pines de los pulsadores S4 y S6 como entrada
	// S6(RD7) y S4(RD13)

	TRISDbits.TRISD7 = 1;
	TRISDbits.TRISD13 = 1;
}

void inic_leds()
{
	// Definir los 8 pines del puerto A conectados a leds (RA7-RA0) como salidas
	// El reso como entradas: 1 = In; 0 = Out
	TRISA = 0xff00;

	/*El pin RA7 lo comparten el led D10 y el pulsador S5.
	 Hemos puesto su direccion a 0= output. Por lo tanto si queremos usar
	 el pulsador S5, habra que cambiarlo.
	*/
}

void tratamiento1_pulsadores()
/*
Encuesta continua sobre S4: mientras este pulsado S4 se apaga D3 y se enciende D4
y al soltar S4 se enciende D3 y se apaga D4
*/
{
	// encuesta sobre el pulsador S4 (RD13)
	while (!PORTDbits.RD13)
	{

		LATAbits.LATA0 = 0; // apagar D3 (RA0)
		LATAbits.LATA1 = 1; // encender D4 (RA1)
	}

	// Al liberar S4
	LATAbits.LATA1 = 0; // apagar D4 (RA1)
	LATAbits.LATA0 = 1; // encender D3 (RA0)
}
