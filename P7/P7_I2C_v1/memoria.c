/*
comentarios!!!
Autorxs y fecha!!!
*/

#include "p24HJ256GP610A.h"
#include "memoria.h"

#include "globals.h"
const unsigned char Mens_LCD_1[] = {"- DSE 2021-22 --"}; // linea 1.1, 16 caracteres
const unsigned char Mens_LCD_2[] = {"--- Pulsa S3  --"}; // linea 2.1, 16 caracteres
const unsigned char Mens_LCD_3[] = {"---- LCD_v1 ----"}; // linea 1.2, 16 caracteres
const unsigned char Mens_LCD_4[] = {"  S4 comienza --"}; // linea 2.2, 16 caracteres
const unsigned char Mens_LCD_5[] = {"S3 st/stop, S6=0"}; // linea 1.3, 16 caracteres
const unsigned char Mens_LCD_6[] = {"Crono: --:--,-  "}; // linea 2.3, 16 caracteres
const unsigned char Mens_LCD_7[] = {"  P 000  T 000  "}; // linea 2.3, 16 caracteres
const unsigned char Mens_LCD_8[] = {" OC1RS     ---- "}; // linea 2.3, 16 caracteres
const unsigned char Mens_LCD_9[] = {" DIST      --   "}; // linea 2.3, 16 caracteres

unsigned char Ventana_LCD[N_LINEAS][TAM_LINEA];

void copiar_FLASH_RAM(const unsigned char *texto, unsigned int i)
{
  unsigned int j;
  for (j = 0; j < TAM_LINEA; j++)
    Ventana_LCD[i][j] = texto[j];
}

void imprimir_valor_pot_lcd()
{
  Ventana_LCD[0][11] = tabla_carac[(duty & 0xF000) >> 12];
  Ventana_LCD[0][12] = tabla_carac[(duty & 0x0F00) >> 8];
  Ventana_LCD[0][13] = tabla_carac[(duty & 0x00F0) >> 4];
  Ventana_LCD[0][14] = tabla_carac[duty & 0x000F];
}