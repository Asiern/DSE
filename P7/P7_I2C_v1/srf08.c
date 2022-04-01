/*
Funciones para utilizar el sensor de distancia

Autoras/es:

Fecha:
*/

#include "i2c_funciones.h"

unsigned int inic_medicion_dis(unsigned char dirI2C)
// Puesta en marcha de una medicion
// Parametro dirI2C corresponde a la direccion I2C del sensor
{
   // A completar
   return LDByteWriteI2C_1(dirI2C, 0x00, 0x51);
}

unsigned int leer_medicion(unsigned char dirI2C, unsigned char *dis)
// Funcion para leer la distancia medida
// Parametro dirI2C corresponde a la direccion I2C del sensor
// Parametro dis proporciona la direccion de un array en el que devolver la medicion
// Cada medicion 2 bytes
{
   // A completar
   return LDByteReadI2C_1(dirI2C, 0x02, dis, 2);
}

void cambiar_direccion(unsigned char dirI2C, unsigned char newdirI2C)
// Fucnion para cambiar la direccion I2C de un sensor
// Parametro dirI2C corresponde a la direccion I2C del sensor
// Parametro newdirI2C corresponde a la nueva direccion I2C que se le va a dar

{
   // A completar
   LDByteWriteI2C_1(dirI2C, 0x00, 0xA0);
   LDByteWriteI2C_1(dirI2C, 0x00, 0xAA);
   LDByteWriteI2C_1(dirI2C, 0x00, 0xA5);
   LDByteWriteI2C_1(dirI2C, 0x00, newdirI2C);
}

unsigned int detectar_direccion(unsigned char *dirI2C)
// Funcion para detectar la direccion I2C del sensor conectado
// Si el sensor responde, la funcion devuelve 0 y actualiza el parametro dirI2C
// Si no responde ningun sensor, devuelve 1
{
   // A completar
   unsigned int i;
   unsigned int em = 1;
   unsigned char value;

   for (i = 0xE0; i < 0xFE; i += 2)
   {
      LDByteReadI2C_1(i, 0x00, &value, 1);
      if (value != 0xFF)
      {
         *dirI2C = i;
         em = 0;
         break;
      }
   }
   return em;
}
