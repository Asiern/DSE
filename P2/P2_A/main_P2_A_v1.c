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
#include "commons.h"

int main()
{
	unsigned int ms, ds, s, min;

	inic_oscilator(); // Seleccion e inicializacion del reloj: 40 MHz

	inic_leds(); // Inicializacio�n leds: sentido y valor inicial.

	inic_crono(&ms, &ds, &s, &min); // Inicializacion variables cronometro.

	inic_Timer7(); // Inicializacion T7 con un periodo de 10 milisegundos.

	while (1)
		cronometro(&ms, &ds, &s, &min);

	return (0);
}
