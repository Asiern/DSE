
/**********************************************************************
* © 2006 Microchip Technology Inc.
*
* FileName:        advolts.c
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
* Richard Fischer   07/14/05  ADC data convert to volts routine
* Priyabrata Sinha  01/27/06  Ported to non-prototype devices
*
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*
* ADDITIONAL NOTES:
*
*
**********************************************************************/

volatile unsigned char adones;
volatile unsigned char adtens;
volatile unsigned char adhunds;
volatile unsigned char adthous;



  
/*---------------------------------------------------------------------
  Function Name: advolt
  Description:   Convert Raw ADC data to volts for LCD display
  Inputs:        Raw ADC data 
  Returns:       None
-----------------------------------------------------------------------*/
void advolt( unsigned int adc_conv_data )
{
 adones = 0;					    // reset values
 adtens = 0;
 adhunds = 0;
 adthous = 0;
 
 while ( adc_conv_data > 0 )
 {
  	if( adc_conv_data > 1241 )		//test for 1 volt or greater
	{
		adones++;			        //increment 1 volt counter
		adc_conv_data -= 1242;		//subtract 1 volt
	}
	
	else if( adc_conv_data > 124 )	//test for 0.1 volt	
	{
		if ( adtens < 9 )
		{
		  adtens++;			//increment tenths
		}
		else 
		{
		  adones++;			//tenths has rolled over
		  adtens = 0;		//so increment ones and reset tenths
		}

		adc_conv_data -= 125;        //test for 0.01 volt
	}

	else if( adc_conv_data > 12 )		
	{
		adhunds++;			//increment hundreths
		adc_conv_data -= 13;
	}
 
	else if ( adc_conv_data <= 12 )
	{
		adthous++;
		adc_conv_data --;
	}
 }

	adones += 0x30;				
 	adtens += 0x30;
 	adhunds += 0x30;
	adthous += 0x30;
} 


