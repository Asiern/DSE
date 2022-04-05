/* Funciones para el modulo ADC1
COMENTARIOS!!!!!
Autorxs:
Fecha:
*/

#include "p24HJ256GP610A.h"
#include "memoria.h"
#include "commons.h"
#include "utilidades.h"
#include "globals.h"

unsigned int cont,Pot;
extern int calcularMedias; // Flag para indicar que hay que calcular las medias
unsigned int mediaTemp, mediaPot;
void inic_ADC1(void)
{
    cont = 0;
    calcularMedias = 0;
    // Inicializacion registro control AD1CON1
    AD1CON1 = 0; // todos los campos a 0

    // Salida de 12 bits o 10 bits
    // AD1CON1bits.AD12B = 0;

    // Comienzo digitalizacion automatico
    // 111=Auto-convert / 010=TMR3 ADC1 y TMR5 ADC2 / 001=INT0 / 000= SAMP
    AD1CON1bits.SSRC = 7;

    // Muestreo simultaneo o secuencial
    // AD1CON1bits.SIMSAM = 0;

    // Comienzo muestreo automático o por programa (SAMP=1)
    // AD1CON1bits.ASAM = 0;

    // Inicializacion registro control AD1CON2
    AD1CON2 = 0; // todos los campos a 0

    // Inicializacion registro control AD1CON3
    AD1CON3 = 0; // todos los campos a 0
    // Reloj con el que funciona el ADC:  0= reloj CPU; 1= RC erlojua
    // AD1CON3bits.ADRC = 0;  //
    AD1CON3bits.SAMC = 31; // Tiempo muestreo = numero de Tad
    AD1CON3bits.ADCS = 1;  // Relacion entre TAD y Tcy TAD = Tcy(ADCS+1)

    // Inicializacion registro control AD1CON4
    AD1CON4 = 0;

    // Inicializacion registro AD1CHS123
    AD1CHS123 = 0; // seleccion del canal 1,2 eta 3

    // Inicializacion registro AD1CHS0
    AD1CHS0 = 0;
    AD1CHS0bits.CH0SA = 5; // elige la entrada analogica conectada

    // AD1CHS0bits.CH0SB = 0;

    // Inicializacion registros AD1CSS
    // Si escaneo secuencial 1, si no 0

    AD1CSSH = 0; // 16-31
    AD1CSSL = 0; // 0-15

    // Inicializacion registros AD1PCFG. Inicialmente todas AN como digitales
    AD1PCFGH = 0xFFFF; // 1= digital / 0= Analog
    AD1PCFGL = 0xFFFF; // Puerto B, todos digitales
    // Inicializar como analogicas solo las que vayamos a usar
    AD1PCFGLbits.PCFG4 = 0; // potenciometro
    AD1PCFGLbits.PCFG5 = 0; // sensor temperatura

    // Bits y campos relacionados con las interrupciones
    IFS0bits.AD1IF = 0;
    IEC0bits.AD1IE = 1;
    // IPC3bits.AD1IP=xx;

    // AD1CON
    AD1CON1bits.ADON = 1; // Habilitar el modulo ADC
}

// comienzo del muestreo por programa
void comienzo_muestreo()
{
    AD1CON1bits.SAMP = 1;
}

// Funcion que recoge el valor del convertidor por encuesta
void recoger_valorADC1()
{

    unsigned int ADCValue = ADC1BUF0;
    while (!AD1CON1bits.DONE)
        ;
    if (AD1CHS0bits.CH0SA == 5)
    {
        Ventana_LCD[0][4] = tabla_carac[(ADCValue & 0x0F00) >> 8];
        Ventana_LCD[0][5] = tabla_carac[(ADCValue & 0x00F0) >> 4];
        Ventana_LCD[0][6] = tabla_carac[(ADCValue & 0x000F)];
        AD1CHS0bits.CH0SA = 4; // elige la entrada analogica conectada
    }
    else
    {
        Ventana_LCD[0][11] = tabla_carac[(ADCValue & 0x0F00) >> 8];
        Ventana_LCD[0][12] = tabla_carac[(ADCValue & 0x00F0) >> 4];
        Ventana_LCD[0][13] = tabla_carac[(ADCValue & 0x000F)];
        AD1CHS0bits.CH0SA = 5; // elige la entrada analogica conectada
    }
    AD1CON1bits.SAMP = 0;
}

// Calcular medias y enviarlas a ventana LCD
void calcular_media()
{
    // Temperatura
    int Temp = mediaTemp / 8;
    mediaTemp = 0;
    Ventana_LCD[2][11] = tabla_carac[(Temp & 0x0F00) >> 8];
    Ventana_LCD[2][12] = tabla_carac[(Temp & 0x00F0) >> 4];
    Ventana_LCD[2][13] = tabla_carac[(Temp & 0x000F)];

    // Potenciometro
    Pot = mediaPot / 8;
    // int Pot = conversion_pot_servo(mediaPot / 8);
    mediaPot = 0;
    Ventana_LCD[2][4] = tabla_carac[(Pot & 0x0F00) >> 8];
    Ventana_LCD[2][5] = tabla_carac[(Pot & 0x00F0) >> 4];
    Ventana_LCD[2][6] = tabla_carac[(Pot & 0x000F)];
}

void mover_servo_pot(int pos)
{
    duty = pos;
}

/**
 * Rutina de atencion a las interrupciones del modulo ADC
 */
void _ISR_NO_PSV _ADC1Interrupt()
{
    unsigned int ADCValue = ADC1BUF0;
    switch (AD1CHS0bits.CH0SA)
    {
    case 4: // Guardar valor del sensor del temperatura
        mediaTemp += ADCValue;
        break;
    case 5: // Guardar valor del sensor de potenciometro
        mediaPot += ADCValue;
        break;
    }
    // Cambiar CHOSA para alternar lecturas entre Potenciometro y Sensor de temperatura
    AD1CHS0bits.CH0SA = AD1CHS0bits.CH0SA == 5 ? 4 : 5;
    cont++; // Aumentar valor del contador de muestras
    if (cont == 16)
    {
        calcularMedias = 1; // Habilitar flag para calcular medias
        cont = 0;
    }
    IFS0bits.AD1IF = 0;   // Apagar flag de interrupcion
    AD1CON1bits.SAMP = 0; // Apagar flag de sampleo
}

// Valores obtenidos => ADCS1 127000 ADCS 43 9800