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
#include "ADC1.h"

int main()
{

	inic_oscilator();  // Seleccion e inicializacion del reloj: 40 MHz
	Init_LCD();		   // Inicializar LCD
	inic_leds();	   // Inicializacio�n leds: sentido y valor inicial.
	inic_pulsadores(); // Inicializar pulsadores
	inic_UART2();	   // Inicializar UART
	inic_ADC1();
	inic_Timer5();

	// Escribir Mensaje inicial en la LCD
	copiar_FLASH_RAM(Mens_LCD_1, 0);
	copiar_FLASH_RAM(Mens_LCD_2, 1);

	// Esperar a la pulsacion de S3 (encuesta)
	while (PORTDbits.RD6)
		;

	reset = 0; // Inicializar reset a 0
	flag = 0;  // Inicializar flag a 0

	init_CN();	   // Inicializar modulo de interrupciones CN
	inic_crono();  // Inicializacion variables cronometro.
	inic_Timer7(); // Inicializacion T7 con un periodo de 10 milisegundos.

	// Escribir Mensaje del cronómetro en la segunda linea
	copiar_FLASH_RAM(Mens_LCD_6, 1);
	copiar_FLASH_RAM(Mens_LCD_7, 0);

	while (1)
	{
		cronometro();
		comienzo_muestreo();
		recoger_valorADC1();
	}
	return (0);
}
