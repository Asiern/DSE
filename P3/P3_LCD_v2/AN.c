#include "AN.h"
#include "p24HJ256GP610A.h"
#include "commons.h"
#include "memoria.h"
#include "LCD.h"
#include "globals.h"
unsigned int flag, pointer, line;

void _ISR_NO_PSV _T7Interrupt()
{
    flag = 1;
    IFS3bits.T7IF = 0; // Apagar el flag de petición de interrupción
}

void _ISR_NO_PSV _T5Interrupt()
{
    lcd_data(Ventana_LCD[line][2]);
    if (pointer == 15)
    {
        pointer = 0;
        // if (line == 1) // Reset pointer pos
        line = line == 0 ? 1 : 0;
    }
    else
        pointer++;
    IFS1bits.T5IF = 0; // Apagar el flag de petición de interrupción
}