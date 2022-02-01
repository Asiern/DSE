
/**********************************************************************
* © 2006 Microchip Technology Inc.
*
* FileName:        main_rtc.c
* Dependencies:    p24HJ256GP610.h
* Processor:       PIC24H
* Compiler:        MPLAB® C30 v2.01 or higher
*
* SOFTWARE LICENSE AGREEMENT:
* Microchip Technology Inc. (“Microchip”) licenses this software to you
* solely for use with Microchip dsPIC® digital signal controller
* products. The software is owned by Microchip and is protected under
* applicable copyright laws.  All rights reserved.
*
* SOFTWARE IS PROVIDED “AS IS.”  MICROCHIP EXPRESSLY DISCLAIMS ANY
* WARRANTY OF ANY KIND, WHETHER EXPRESS OR IMPLIED, INCLUDING BUT NOT
* LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
* PARTICULAR PURPOSE, OR NON-INFRINGEMENT. IN NO EVENT SHALL MICROCHIP
* BE LIABLE FOR ANY INCIDENTAL, SPECIAL, INDIRECT OR CONSEQUENTIAL
* DAMAGES, LOST PROFITS OR LOST DATA, HARM TO YOUR EQUIPMENT, COST OF
* PROCUREMENT OF SUBSTITUTE GOODS, TECHNOLOGY OR SERVICES, ANY CLAIMS
* BY THIRD PARTIES (INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF),
* ANY CLAIMS FOR INDEMNITY OR CONTRIBUTION, OR OTHER SIMILAR COSTS.
*
* REVISION HISTORY:
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Author            Date      Comments on this revision
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Richard Fischer   07/14/05  Initial Release
* Priyabrata Sinha  01/27/06  Ported to non-prototype devices 
* Priyabrata Sinha  01/30/06  Added config macros
*
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*
* ADDITIONAL NOTES:  
*
* Simple demo program showing a RTC and ADC conversion on the LCD
* DMA code is included here but not fully tested.
*
* C30 Optimization Level: -O1
*
**********************************************************************/

#include "p24HJ256GP610A.h"
#include "lcd.h"
#include "common.h"

_FOSCSEL(FNOSC_PRIPLL);
_FOSC(FCKSM_CSDCMD & OSCIOFNC_OFF & POSCMD_XT);
_FWDT(FWDTEN_OFF);

void Update_LCD( void );
const char mytext[] =  "   PIC24H Demo  ";
const char mytext1[] = "Press S3 to cont";
const char time_msg[] = "Time 00: 00: 00 ";
const char adc_msg1[] = " RP5 = 0.00 Vdc  ";

// Using internal FRC oscillator at 8MHz
// Fosc = Fin * (DIVISOR<8:0> + 2 / ((PRESCLR<4:0> +2) * (PLLPOST<1:0> +1) )
// DIVISOR<8:0> bits located in PLLFBF SFR ---> (PLL Multiplier)
// PLLPOST<1:0> bits located in CLKDIV SFR ---> (PLL VCO output divide)
// PRESCLR<4:0> bits located in CLKDIV SFR ---> (PLL Phase Detector input divide)

int main ( void )
{
	/* Initialize some general use variables */
	hours, minutes, seconds = 0;
	rtc_lcd_update = 0;

        //The settings below set up the oscillator and PLL for 16 MIPS as
        //follows:
        //            Crystal Frequency  * (DIVISOR+2)
        // Fcy =     ---------------------------------
        //              PLLPOST * (PRESCLR+2) * 4	
        PLLFBD = 0x00A0;
        CLKDIV = 0x0048;
 
	/* set LEDs (D3-D10/RA0-RA7) drive state low */
	LATA = 0xFF00; 
	/* set LED pins (D3-D10/RA0-RA7) as outputs */
	TRISA = 0xFF00; 
	
	/* Initialize LCD Display */
	Init_LCD();

	/* Welcome message */
	home_clr();
	puts_lcd( (char*) &mytext[0], sizeof(mytext) -1 );
	line_2();
	puts_lcd( (char*) &mytext1[0], sizeof(mytext1) -1 );
		
	/* wait here until switch S3 is pressed */
	while ( PORTDbits.RD6 );
		    
  	/* Initialize Timer 1 for 32KHz real-time clock operation */
    Init_Timer1();

    /* Initial LCD message for TOD */
	home_clr();
	puts_lcd( (char*) &time_msg[0], sizeof(time_msg) -1 );
 	line_2();
	puts_lcd( (char*) &adc_msg1[0], sizeof(adc_msg1) -1 );
          
    /* Initialize ADC  */
    Init_ADC();
    
    /* Initialize DMA Channel 0 */
//    Init_DMAC0();
      
    /* Infinite Loop */
    while ( 1 ) 
    { 
      /* check if time to update LCD with TOD data */  
      if ( rtc_lcd_update ) 
	  {
		 hexdec( hours );
		 Update_LCD();
		 rtc_lcd_update = 0;
      }	 	
      /* check if time to update LCD with ADC data */
  	  if ( adc_lcd_update ) 
  	  {
       	 line_2();
		 advolt( temp1 );
       	 cursor_right();
       	 cursor_right();
       	 cursor_right();  
       	 cursor_right();
       	 cursor_right();
       	 cursor_right();
       	 cursor_right();
		 lcd_data( adones );
       	 cursor_right();
	  	 lcd_data( adtens );
	  	 lcd_data( adhunds );	
	     adc_lcd_update = 0;
	  }
	};
}


/*---------------------------------------------------------------------
  Function Name: Update_LCD
  Description:   Update LCD for real-time clock data
  Inputs:        None
  Returns:       None
-----------------------------------------------------------------------*/
void Update_LCD( void )
{

   	/* position LCD cursor at column, row */
  	home_it();
    cursor_right();
    cursor_right();
    cursor_right();
    cursor_right();
    cursor_right();
	lcd_data(tens + 0x30);
	lcd_data(ones + 0x30);
    
    hexdec( minutes );
    /* position LCD cursor at column, row */
	cursor_right();
    cursor_right();
	lcd_data(tens + 0x30);
	lcd_data(ones + 0x30);
	 
  	hexdec( seconds );
	/* position LCD cursor at column, row */
	cursor_right();
    cursor_right();
	lcd_data(tens + 0x30);
	lcd_data(ones + 0x30);
   
}
