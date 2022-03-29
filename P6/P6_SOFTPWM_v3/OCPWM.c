/*
Funciones relacionadas con el modulo OC para generar pulsos PWM

Comentarios!!!!!!!!!!!!!!

Autorxs:
Fecha:
*/

#include "p24HJ256GP610A.h"
#include "commons.h"
#include "globals.h"
unsigned int DUTY_MIN = T20ms / 20 * MINPWM; // valor minimo de DUTY
unsigned int DUTY_MAX = T20ms / 20 * MAXPWM; // valor maximo de DUTY

void inic_duty()
{
    duty = DUTY_MAX / 2;
}
