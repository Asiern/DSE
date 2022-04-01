/*
Komentarioak!!!
Egileak eta data!!!
*/

#include "p24HJ256GP610A.h"
#include "commons.h"

// Funcion para obtener los caracteres de un valor de dos digitos (<100)
// Parametros:
// val, valor numerico del que se quieren obtener los caracteres ASCII
// dir, direccion a partir de la cual queremos que la funcion devuelva los codigos ASCII
// En dir estara el caracter de mas peso y en dir+1 el de menos peso

unsigned char tabla_carac[16] = "0123456789ABCDEF";
void conversion_tiempo(unsigned char *dir, unsigned int val)
{
    unsigned char dig;
    if (val > 99)
    {
        while (1)
            ;
    }
    else
    {
        dig = val / 10;
        dig = tabla_carac[dig];
        *dir = dig;
        dir++;
        dig = val % 10;
        dig = tabla_carac[dig];
        *dir = dig;
    }
}

void conversion_hex(unsigned char *dir, unsigned int val)
{
    unsigned char dig;
    if (val > 99)
    {
        while (1)
            ;
    }
    else
    {
        dig = val / 16;
        dig = tabla_carac[dig];
        *dir = dig;
        dir++;
        dig = val % 16;
        dig = tabla_carac[dig];
        *dir = dig;
    }
}

unsigned int conversion_pot_servo(unsigned int valor_pot)
{
    unsigned int DUTY_MIN = T20ms / 20 * MINPWM; // valor minimo de DUTY
    unsigned int DUTY_MAX = T20ms / 20 * MAXPWM; // valor maximo de DUTY

    unsigned int pos =DUTY_MIN + ((valor_pot / 1023.0) * (DUTY_MAX - DUTY_MIN));
    
    return pos;
}