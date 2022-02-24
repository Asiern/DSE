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
#include "UART2_RS232.h"

int main()
{

	inic_oscilator(); // Seleccion e inicializacion del reloj: 40 MHz

	Init_LCD();

	copiar_FLASH_RAM(Mens_LCD_1, 0);
	copiar_FLASH_RAM(Mens_LCD_2, 1);
	line_1();
	puts_lcd(&Ventana_LCD[0], 16);
	line_2();
	puts_lcd(&(Ventana_LCD[1]), 16);

	while (PORTDbits.RD6)
		Nop();

	reset = 0;
	init_CN();

	inic_leds(); // Inicializacio�n leds: sentido y valor inicial.

	inic_crono(); // Inicializacion variables cronometro.

	flag = 0;
	inic_Timer7(); // Inicializacion T7 con un periodo de 10 milisegundos.

	copiar_FLASH_RAM(Mens_LCD_6, 1);
	line_2();
	puts_lcd(Ventana_LCD[1], 16);
	inic_UART2();
	enviar_UART2_ventana();
	recibir_teclas(12);
	line_1();
	puts_lcd(Ventana_LCD[0], 16);
	line_2();
	while (1)
		cronometro();
	return (0);
}
