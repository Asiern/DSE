
/**********************************************************************
* © 2006 Microchip Technology Inc.
*
* FileName:        init_DMAC0.c
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
* PARTICULAR PURPOSE, OR NON-INFRINGEMENT. IN NO EVEN111T SHALL MICROCHIP
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
* Richard Fischer   07/14/05  DMA CH0 module initialization
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
  Function Name: Init_DMAC0
  Description:   Initialize DMA Channel 0
  Inputs:        None
  Returns:       None
-----------------------------------------------------------------------*/
void Init_DMAC0( void )
{
	/* DMA buffer 1 Start address for DPSRAM Address */
	DMA0STA = 0x0000;

	/* DMA buffer 2 Start address for DPSRAM Address */
	DMA0STB = 0x0100;

	/* initialize DMA Peripheral SFR Address */
	DMA0PAD = (int) &ADC1BUF0;
	
	/* Set transfer count to 256 */
	DMA0CNT = 256;

	/* reset status register */
	DMACS0 = 0x0000;

	/* DMA Channel Setup  */
    /* Word transfer, Read from peripheral/Write to DPSRAM
       Interrupt when block transfer complete
       Automatic DMA transfer initiation by DMA request
       Register indirect
       One-shot mode, ping-pong disabled 
       ADC1 IRQ numer = 13 (D) */
	DMA0CON = 0x010D;
	
	/* set DMA CH0 interrupt priority level to 4 */
	IPC1bits.DMA0IP = 4;	
	/* reset DMA CH0 interrupt flag */ 
	IFS0bits.DMA0IF = 0;
	/* enable DMA CH0 interrupts */	  
	IEC0bits.DMA0IE = 1;

	/* enable DMA Channel 0 */
	DMA0CONbits.CHEN = 1;
}
