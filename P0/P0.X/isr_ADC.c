
/**********************************************************************
* © 2006 Microchip Technology Inc.
*
* FileName:        isr_ADC.c
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
* Richard Fischer   07/14/05  ADC module interrupt handler
* Priyabrata Sinha  01/27/06  Ported to non-prototype devices
*
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*
* ADDITIONAL NOTES:
*
*
**********************************************************************/

#include "p24HJ256GP610A.h"
#include "common.h"

volatile unsigned int temp1;
volatile unsigned char adc_lcd_update;


/*---------------------------------------------------------------------
  Function Name: ADCInterrupt
  Description:   ADC Interrupt Handler
  Inputs:        None
  Returns:       None
-----------------------------------------------------------------------*/
void __attribute__((__interrupt__)) _ADC1Interrupt( void )
{
	int count;

	/* Simple I am here indicator */
	if ( count++ == 2000 ) {
		__builtin_btg( (unsigned int *)&LATA, 0 );
		count = 0;
	}
	
	/* Save off the RP5 Potentiometer data */
	temp1 = ADC1BUF0;             

	/* set flag to update LCD */
	adc_lcd_update = 1;
	
	/* reset ADC interrupt flag */
	IFS0bits.AD1IF = 0;           
}

