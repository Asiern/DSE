/*
Cronometro mediante leds.
Control de timer 1 por encuesta.
Se utilizan los siguientes leds:
-------- // COMPLETAD!!!!!!

Autorxs:
Fecha:
*/

#include "p24HJ256GP610A.h"

#include "oscilator.h"
#include "GPIO.h"
#include "timers.h"
#include "CN.h"
#include "commons.h"
#include "globals.h"
#include "LCD.h"
#include "memoria.h"

int main()
{
	inic_oscilator(); // Seleccion e inicializacion del reloj: 40 MHz
	Init_LCD();
	inic_leds();	   // Inicializacio�n leds: sentido y valor inicial.
	inic_pulsadores(); // Inicializar pulsadores
	inic_Timer5();

	copiar_FLASH_RAM(Mens_LCD_1, 0);
	copiar_FLASH_RAM(Mens_LCD_2, 1);

	while (PORTDbits.RD6)
		;

	reset = 0;
	flag = 0;

	init_CN();
	inic_crono();  // Inicializacion variables cronometro.
	inic_Timer7(); // Inicializacion T7 con un periodo de 10 milisegundos.

	copiar_FLASH_RAM(Mens_LCD_6, 1);
	while (1)
		cronometro();

	return (0);
}
