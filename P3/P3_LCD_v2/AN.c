#include "AN.h"
#include "p24HJ256GP610A.h"
#include "commons.h"
#include "memoria.h"
#include "LCD.h"
#include "globals.h"
unsigned int flag, line;

void _ISR_NO_PSV _T7Interrupt()
{
    flag = 1;
    IFS3bits.T7IF = 0; // Apagar el flag de petición de interrupción
}

void _ISR_NO_PSV _T5Interrupt()
{
    if (line == 1)
        line_1();
    else if (line == 2)
        line_2();
    else
        return;

    puts_lcd(Ventana_LCD[line - 1], 16);
    IFS1bits.T5IF = 0; // Apagar el flag de petición de interrupción
}