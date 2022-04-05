/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
;   Programa adaptado: i2c_Func.c  ;February 21, 2007   ;Martin Bowman
;~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
;	Filename:	i2c_funtzioak.c
;	Date:       March, 2022
;~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
#include <p24HJ256GP610A.h>

/*******************************************************************
 * Function: InitI2C_1()
 * Overview:	Initializes the I2C(1) peripheral
 * Note:     Sets up Master mode, No slew rate control, 400 kHz
 * This function will initialize the I2C(1) peripheral.
 ********************************************************************/
void InitI2C_1()
{
  // I2CBRG=(Fcy/Fscl)-(Fcy/10000000)-1
  // I2C1BRG = 95; 	//400 kHz & Fcy= 40 MHz
  // I2C1BRG = 195; 	//200 kHz & Fcy= 40 MHz

  // I2C1BRG = 395; 	//100 kHz & Fcy= 40 MHz
  // I2C1BRG = 246; 	//100 kHz & Fcy= 25 MHz
  // I2C1BRG = 197; 	//100 kHz & Fcy= 20 MHz

  I2C1BRG = 197;         // 100 kHz & Fcy= 20 MHz //First set the I2C(1) BRG Baud Rate
  I2C1CON = 0x1200;      // Iniciar en modo maestro, No Slew Rate, I2C deshabilitado
  I2C1CONbits.I2CEN = 1; // Habilitar I2C
}

/*******************************************************************
 * Function: StartI2C_1()
 * Overview: Generates an I2C Start Condition
 * This function generates an I2C start condition and returns status of the Start.
 ********************************************************************/
unsigned int StartI2C_1()
{
  unsigned int time_out;
  I2C1CONbits.SEN = 1; // Generate Start Condition
  time_out = 0;
  // Wait for Start Condition
  while (I2C1CONbits.SEN && (time_out < 1000))
    time_out++;
  if (time_out >= 1000)
    return 1;
  return 0;
}

/*******************************************************************
 * Function: RestartI2C_1()
 * Overview: Generates a restart condition and optionally returns status
 * This function generates an I2C Restart condition and returns status of the Restart.
 ********************************************************************/
unsigned int RestartI2C_1()
{
  unsigned int time_out;
  I2C1CONbits.RSEN = 1; // Generate Restart
  time_out = 0;
  // Wait for restart
  while (I2C1CONbits.RSEN && (time_out < 1000))
    time_out++;
  if (time_out >= 1000)
    return 1;
  return 0;
}

/*******************************************************************
 * Function: StopI2C_1()
 * Overview:	Generates a bus stop condition
 * This function generates an I2C stop condition and returns status of the Stop.
 ********************************************************************/
unsigned int StopI2C_1()
{
  unsigned int time_out;
  I2C1CONbits.PEN = 1; // Generate Stop Condition
  time_out = 0;
  // Wait for Stop
  while (I2C1CONbits.PEN && (time_out < 1000))
    time_out++;
  if (time_out >= 1000)
    return 1;
  return 0;
}

/*********************************************************************
 * Function: IdleI2C_1()
 * Overview: Waits for bus to become Idle
 ********************************************************************/
unsigned int IdleI2C_1()
{
  unsigned int time_out;
  time_out = 0;
  // Wait for bus Idle
  while (I2C1STATbits.TRSTAT && (time_out < 1000))
    time_out++;
  if (time_out >= 1000)
    return 1;
  return 0;
}

/*******************************************************************
 * Function: WriteI2C_1()
 * Input:	Byte to write
 * Overview: Writes a byte out to the bus
 * This function transmits the byte passed to the function
 ********************************************************************/
unsigned int WriteI2C_1(unsigned char byte)
{
  unsigned int time_out;
  I2C1TRN = byte; // Load byte to I2C1 Transmit buffer
  time_out = 0;
  // wait for data transmission
  while (I2C1STATbits.TBF && (time_out < 1000))
    time_out++;
  if (time_out >= 1000)
    return 1;
  return 0;
}

/*******************************************************************
 * Function: ACKCheck_1(unsigned int *ACKstatus)
 * Input:	Acknowledge status pointer
 * Overview:	Return the Acknowledge status on the bus
 ********************************************************************/
unsigned int ACKCheck_1(unsigned int *ACKstatus)
{
  unsigned int time_out;
  time_out = 0;
  // wait for ACK
  while (I2C1STATbits.TRSTAT && (time_out < 1000))
    time_out++;
  if (time_out >= 1000)
    return 1;
  *ACKstatus = I2C1STATbits.ACKSTAT;
  return (0);
}

/*******************************************************************
 * Function: NotAckI2C_1()
 * Overview:	Generates a NO Acknowledge on the Bus
 ********************************************************************/
unsigned int NotAckI2C_1()
{
  unsigned int time_out;
  I2C1CONbits.ACKDT = 1; // Set for NotACK
  I2C1CONbits.ACKEN = 1;
  time_out = 0;
  // wait for ACK to complete
  while (I2C1CONbits.ACKEN && (time_out < 1000))
    time_out++;
  if (time_out >= 1000)
    return 1;
  return 0;
}

/*******************************************************************
 * Function: AckI2C_1()
 * Overview:	Generates an Acknowledge
 ********************************************************************/
unsigned int AckI2C_1()
{
  unsigned int time_out;
  I2C1CONbits.ACKDT = 0; // Set for ACK
  I2C1CONbits.ACKEN = 1;
  time_out = 0;
  // wait for ACK to complete
  while (I2C1CONbits.ACKEN && (time_out < 1000))
    time_out++;
  if (time_out >= 1000)
    return 1;
  return 0;
}

/*******************************************************************
 * Function: getI2C_1()
 * Input:	read byte pointer
 * Output:   contents of I2C1 receive buffer
 * Overview:	Read a single byte from Bus
 ********************************************************************/
unsigned int getI2C_1(unsigned char *byte)
{
  int time_out;
  I2C1CONbits.RCEN = 1; // Enable Master receive
  time_out = 0;
  // Wait for receive bufer to be full
  while (!I2C1STATbits.RBF & (time_out < 1000))
    time_out++;
  if (time_out >= 1000)
    return (1);
  *byte = I2C1RCV; // data in buffer
  return (0);
}

/*******************************************************************
 * Function: getsI2C_1()
 * Input:	array pointer, Length
 * Overview:	read Length number of Bytes into array
 ********************************************************************/
unsigned int getsI2C_1(unsigned char *rdptr, unsigned char Length)
{
  while (Length--)
  {
    // get a single byte
    if (getI2C_1(rdptr) != 0)
      return (1);
    rdptr++;

    // Acknowledge until all read
    if (Length)
      if (AckI2C_1() != 0)
        return (2);
  }
  return (0);
}

/******************************************************************
 * Function: LDByteReadI2C_1()
 * Input:	I2C_address, Register_address, *Data, Length
 * Overview:	Performs a low density read of Length bytes and stores
 *           in *Data array starting at Register_address
 ********************************************************************/
unsigned int LDByteReadI2C_1(unsigned char I2C_address, unsigned char Register_address, unsigned char *Data, unsigned char Length)
{
  unsigned int ACKstatus;

  if (IdleI2C_1())
    return (1);
  if (StartI2C_1())
    return (2);
  if (WriteI2C_1(I2C_address))
    return (3);
  if (ACKCheck_1(&ACKstatus))
    return (4);
  if (WriteI2C_1(Register_address))
    return (3);
  if (ACKCheck_1(&ACKstatus))
    return (4);
  if (RestartI2C_1())
    return (6);
  if (WriteI2C_1(I2C_address | 0x01))
    return (3);
  if (ACKCheck_1(&ACKstatus))
    return (4);
  if (getsI2C_1(Data, Length))
    return (7);
  if (NotAckI2C_1())
    return (8);
  if (StopI2C_1())
    return (5);

  return (0);
}

/*******************************************************************
 * Function: LDByteWriteI2C_1()
 * Input:    I2C_address, 8 - bit Register_address, data
 * Overview:	Write a byte to low density device at Register_address
 ********************************************************************/
unsigned int LDByteWriteI2C_1(unsigned char I2C_address, unsigned char Register_address, unsigned char data)
{
  unsigned int ACKstatus;

  if (IdleI2C_1())
    return (1);
  if (StartI2C_1())
    return (2);
  if (WriteI2C_1(I2C_address))
    return (3);
  if (ACKCheck_1(&ACKstatus))
    return (4);
  if (WriteI2C_1(Register_address))
    return (3);
  if (ACKCheck_1(&ACKstatus))
    return (4);
  if (WriteI2C_1(data))
    return (3);
  if (ACKCheck_1(&ACKstatus))
    return (4);
  if (StopI2C_1())
    return (5);
  return (0);
}
