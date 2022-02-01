
/**********************************************************************
* © 2006 Microchip Technology Inc.
*
* FileName:        init_timer1.c
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
* Richard Fischer   07/14/05  Initialization of Timer1 for RTC demo
* Priyabrata Sinha  01/27/06  Ported to non-prototype devices
*
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*
* ADDITIONAL NOTES:
*
*
**********************************************************************/


#include "p24HJ256GP610A.h"

/* Set SLEEP to 1 is dsPIC will enter sleep in main loop */
#define SLEEP  0

   
    
/*---------------------------------------------------------------------
  Function Name: Init_Timer1
  Description:   Initialize Timer1 for 1 second intervals
  Inputs:        None
  Returns:       None
-----------------------------------------------------------------------*/
void Init_Timer1( void )
{
	/* declare temp variable for CPU IPL storing */
	int current_cpu_ipl;
	
	/* ensure Timer 1 is in reset state */
	T1CON = 0;

	/* reset Timer 1 interrupt flag */
 	IFS0bits.T1IF = 0;
 	
 	/* set Timer1 interrupt priority level to 4 */
	IPC0bits.T1IP = 4;

	/* enable Timer 1 interrupt */
 	IEC0bits.T1IE = 1;
 	  	
	/* set Timer 1 period register */
	PR1 = 0x8000;

 	/* select external timer clock */
	T1CONbits.TCS = 1;

	/* disable interrupts for unlock sequence below */
//	SET_AND_SAVE_CPU_IPL(current_cpu_ipl, 7);	
	
 char a, b, c, *p;

 a = 2;
 b = 0x46;
 c = 0x57;
 p = (char *)&OSCCON;

	/* enable 32KHz Oscillator here 
       low byte unlock sequence and enable LP Oscillator */
 	asm volatile ("mov.b %1,[%0] \n"
                  "mov.b %2,[%0] \n"
                  "mov.b %3,[%0] \n" : /* no outputs */ : "r"(p), "r"(b), "r"(c),
                                                          "r"(a));
	
	/* restore CPU IPL value after executing unlock sequence */
//	RESTORE_CPU_IPL(current_cpu_ipl);
		 
 	/* enable Timer 1 and start the count */ 
	T1CONbits.TON = 1;
	
	
#if  SLEEP == 1
    /* If main loop will enter SLEEP mode then wait here 
       until Oscillator starts and Timer begins to count */
	while ( TMR1 < 2 );	
#endif	

}
