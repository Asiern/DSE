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
#include "OCPWM.h"
#include "utilidades.h"

int calcularMedias;
unsigned int servomode;
int main()
{
	servomode = 0;
	inic_oscilator();  // Seleccion e inicializacion del reloj: 40 MHz
	Init_LCD();		   // Inicializar LCD
	inic_leds();	   // Inicializacio�n leds: sentido y valor inicial.
	inic_pulsadores(); // Inicializar pulsadores
	inic_UART2();	   // Inicializar UART
	inic_ADC1();
	inic_Timer5();
	inic_OC1();
	inic_Timer2_PWM();

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
	inic_Timer3();

	// Escribir Mensaje del cronómetro en la segunda linea
	copiar_FLASH_RAM(Mens_LCD_6, 1);
	copiar_FLASH_RAM(Mens_LCD_8, 0);
	copiar_FLASH_RAM(Mens_LCD_7, 2);
	while (1)
	{
		if (calcularMedias == 1)
		{
			calcularMedias = 0;
			calcular_media();
			// if (servomode == 1)
			// 	mover_servo_pot(conversion_pot_servo(mediaPot));
		}
		cronometro();
	}
	return (0);
}
