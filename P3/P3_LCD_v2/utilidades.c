/*
Komentarioak!!!
Egileak eta data!!!
*/

#include "p24HJ256GP610A.h"

// Funcion para obtener los caracteres de un valor de dos digitos (<100)
// Parametros:
// val, valor numerico del que se quieren obtener los caracteres ASCII
// dir, direccion a partir de la cual queremos que la funcion devuelva los codigos ASCII
// En dir estara el caracter de mas peso y en dir+1 el de menos peso

unsigned char tabla_carac[16] = "0123456789";
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
