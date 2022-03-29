/*
Funciones relacionadas con el modulo OC para generar pulsos PWM

Comentarios!!!!!!!!!!!!!!

Autorxs:
Fecha:
*/

#include "p24HJ256GP610A.h"
#include "commons.h"
#include "OCPWM.h"

unsigned int DUTY_MIN = T20ms / 20 * MINPWM; // valor minimo de DUTY
unsigned int DUTY_MAX = T20ms / 20 * MAXPWM; // valor maximo de DUTY

void inic_OC1()
{
    OC1CON = 0;
    // OC1CONbits.OCM=0b000;     // deshabilitar OC1
    // OC1CONbits.OCTSEL=0;      // seleccionar T2 para el OC

    OC1R = T20ms; // Inicializar pulso con duracion intermedia
    OC1RS = OC1R; // inicializar registro secundario

    OC1CONbits.OCM = 0b110; // habilitar OC1 en modo PWM
}
