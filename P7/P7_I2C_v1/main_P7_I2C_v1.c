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
#include "srf08.h"
#include "i2c_funciones.h"

int calcularMedias;

unsigned int servomode = UART_MODE;
unsigned char dir;
unsigned int direccion = 0xE8;
unsigned char distancia[2];

int main()
{

	inic_oscilator();  // Seleccion e inicializacion del reloj: 40 MHz
	Init_LCD();		   // Inicializar LCD
	inic_leds();	   // Inicializacio�n leds: sentido y valor inicial.
	inic_pulsadores(); // Inicializar pulsadores
	inic_UART2();	   // Inicializar UART
	inic_ADC1();
	inic_Timer5();
	inic_duty();
	inic_Timer2_PWM();
	inic_Timer3();

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
	copiar_FLASH_RAM(Mens_LCD_8, 0);
	copiar_FLASH_RAM(Mens_LCD_6, 1);
	copiar_FLASH_RAM(Mens_LCD_7, 2);
	copiar_FLASH_RAM(Mens_LCD_9, 3);

	inic_Timer6();
	InitI2C_1();
	inic_medicion_dis(direccion);
	sensor_listo = 0;
	T6CONbits.TON = 1; // Encender timer

	while (1)
	{
		if (calcularMedias == 1)
		{
			calcularMedias = 0;
			calcular_media();

			if (servomode == POT_MODE)
			{
				mover_servo_pot(conversion_pot_servo(Pot));
				imprimir_valor_pot_lcd();
			}
		}

		if (sensor_listo)
		{
			// Procesoar medicion anterior
			leer_medicion(direccion, distancia);
			unsigned int distancia_total = (distancia[0] << 8) | distancia[1];
			conversion_decimal(&(Ventana_LCD[3][11]), distancia_total);

			// Iniciar nueva medicion
			inic_medicion_dis(direccion);
			sensor_listo = 0;
			TMR6 = 0;
			T6CONbits.TON = 1; // Encender timer
		}

		cronometro();
	}
	return (0);
}
