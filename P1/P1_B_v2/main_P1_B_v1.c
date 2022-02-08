
#include "p24HJ256GP610A.h"
#include "commons.h"
#include "GPIO.h"
#include "CN.h"

int main()
{
    inic_leds();
    inic_pulsadores();

    while (PORTDbits.RD6)
    {
        // Esperamos a que el pulsador S3 sea pulsado (Encuesta)
        Nop();
    }

    LATAbits.LATA6 = 0; // Apagamos el led D9

    LATAbits.LATA5 = 1; // Encendemos el led D8

    inic_CN(); // Inicializamos las interrupciones
    while (1)
    {
        Nop();
    }
}
