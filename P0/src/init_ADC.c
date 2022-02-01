
/**********************************************************************
* © 2006 Microchip Technology Inc.
*
* FileName:        init_ADC.c
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
* Richard Fischer   07/14/05  ADC module initialization
* Priyabrata Sinha  01/27/06  Ported to non-prototype devices
*
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*
* ADDITIONAL NOTES:
*
*
**********************************************************************/


#include "p24HJ256GP610A.h"

   
    
/*---------------------------------------------------------------------
  Function Name: Init_ADC
  Description:   Initialize ADC module
  Inputs:        None
  Returns:       None
-----------------------------------------------------------------------*/
void Init_ADC( void )
{

	/* set port configuration here */ 		
 	AD1PCFGLbits.PCFG4 = 0;         // ensure AN4/RB4 is analog (Temp Sensor)
 	AD1PCFGLbits.PCFG5 = 0;         // ensure AN5/RB5 is analog (Analog Pot)
 
 	/* set channel scanning here, auto sampling and convert, 
 	   with default read-format mode */
	AD1CON1 = 0x00E4;
	/* select 12-bit, 1 channel ADC operation */
	AD1CON1bits.AD12B = 1;
	
	/* enable DMA mode (ADC module sends all results 
	   to ADBUF0 and interrupts on each result */
//	ADCON1bits.ADDMAEN = 1;
	
	/* No channel scan for CH0+, Use MUX A,  
	   SMPI = 1 per interrupt, Vref = AVdd/AVss */
	AD1CON2 = 0x0000;
	
	/* Set Samples and bit conversion time */
	AD1CON3 = 0x032F; 
        	
	/* set channel scanning here for AN4 and AN5 */
	AD1CSSL = 0x0000;
	
	/* channel select AN5 */
	AD1CHS0 = 0x0005;
	
	/* reset ADC interrupt flag */
	IFS0bits.AD1IF = 0;           

	/* enable ADC interrupts, disable this interrupt if the DMA is enabled */	  
	IEC0bits.AD1IE = 1;       

	/* turn on ADC module */
	AD1CON1bits.ADON = 1;          	
}
