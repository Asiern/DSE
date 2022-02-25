#include "AN.h"
#include "p24HJ256GP610A.h"
#include "commons.h"

#include "globals.h"
unsigned int flag;

void _ISR_NO_PSV _T7Interrupt()
{
    flag = 1;
    IFS3bits.T7IF = 0; // Apagar el flag de petición de interrupción
}