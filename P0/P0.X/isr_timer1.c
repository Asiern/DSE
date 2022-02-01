  
/**********************************************************************
* © 2006 Microchip Technology Inc.
*
* FileName:        isr_timer1.c
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
* Richard Fischer   07/14/05  Timer1 interrupt handler for RTC
* Priyabrata Sinha  01/27/06  Ported to non-prototype devices
*
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*
* ADDITIONAL NOTES:
*
*
**********************************************************************/

#include "p24HJ256GP610A.h"


volatile unsigned char hours;
volatile unsigned char minutes;
volatile unsigned char seconds;
volatile unsigned char rtc_lcd_update;

void __builtin_btg(unsigned int *, unsigned int);

 

/*---------------------------------------------------------------------
  Function Name: _T1Interrupt
  Description:   Timer1 Interrupt Handler
  Inputs:        None
  Returns:       None
-----------------------------------------------------------------------*/
void __attribute__((__interrupt__)) _T1Interrupt( void )
{

	if ( seconds < 59 )          // is cummulative seconds < 59?
	{
		seconds++;               // yes, so increment seconds
	}
	else                         // else seconds => 59     
	{
		seconds = 0x00;          // reset seconds
		if ( minutes < 59 )      // is cummulative minutes < 59?
		{
			minutes++;           // yes, so updates minutes  
		}
		else                     // else minutes => 59
		{
			minutes = 0x00;      // reset minutes
			if ( hours < 23 )    // is cummulative hours < 23
			{
				hours ++;        // yes, so update hours
			}
			else
			{
				hours = 0x00;    // reset time
			}		  
		}
	}     

	/* set flag to update LCD */
	rtc_lcd_update = 1;
	
	/* Toggle LEDs at 1 Hz rate */
	__builtin_btg((unsigned int *)&LATA, 7);
	__builtin_btg((unsigned int *)&LATA, 6);
	__builtin_btg((unsigned int *)&LATA, 5);
	__builtin_btg((unsigned int *)&LATA, 4);
	__builtin_btg((unsigned int *)&LATA, 3);
	__builtin_btg((unsigned int *)&LATA, 2);	
	__builtin_btg((unsigned int *)&LATA, 1);

	/* reset Timer 1 interrupt flag */
 	IFS0bits.T1IF = 0;
}
