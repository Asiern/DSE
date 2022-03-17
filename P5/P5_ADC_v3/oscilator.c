#include "p24HJ256GP610A.h"

// Inicializacion del modulo oscilator
// Para ver la configuracion:
//      Barra herramientas: Windows -> PIC Memory Views -> Configuration Bits

// Configuracion
#pragma config FNOSC = PRIPLL // Primary oscillator (XT, HS, EC) w/PLL
#pragma config FCKSM = CSECMD // Enable Clok switching
#pragma config OSCIOFNC = OFF // OSC2 is clock
#pragma config POSCMD = XT	  // XT oscillator
#pragma config FWDTEN = OFF	  // Watchdog Timer: Disabled

void inic_oscilator()
{

	// Reloj a 40 MHz para que las instrucciones se ejecuten a 20 MHz.
	// Fosc= Fin*M(N1*N2),  Fcy=Fosc/2
	// Fosc= 8*20/(2*2)= 40MHz for 8MHz input clock

	PLLFBD = 20 - 2;		// M=PLLFBD+2
	CLKDIVbits.PLLPOST = 0; // N2=(PLLPOST+1)*2
	CLKDIVbits.PLLPRE = 0;	// N1=PLLPRE+2
	RCONbits.SWDTEN = 0;	// Disable Watch Dog Timer

	// Clock switch to incorporate PLL
	__builtin_write_OSCCONH(0x03); // Initiate Clock Switch to Primary
								   // Oscillator with PLL (NOSC=0b011)
	__builtin_write_OSCCONL(0x01); // Start clock switching

	while (OSCCONbits.COSC != 0b011)
		; // Wait fot Clock switch to occur

	// Wait for PLL to lock
	while (OSCCONbits.LOCK != 1)
	{
	}
}
