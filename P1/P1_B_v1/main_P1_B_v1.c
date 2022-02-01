/*
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1
 * Comentar que hace el programa (enunciado)!!!!!!!!!!!!!
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
Egileak: Izaskun
Data: Febrero 2020
*/

#include "p24HJ256GP610A.h"
#include "commons.h"
#include "GPIO.h"
#include "CN.h"

int main()
{
	inic_leds();
	inic_pulsadores();
	inic_CN();

	LATAbits.LATA0 = 1;

	while (1)
	{
		tratamiento1_pulsadores();
	}
}
