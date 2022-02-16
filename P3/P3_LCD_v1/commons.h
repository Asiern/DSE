// definiciones generales

#define Nop() __builtin_nop()

#define _ISR_NO_PSV __attribute__((interrupt, no_auto_psv))

/////////////////////////////////////
// definiciones para la pantalla LCD
/////////////////////////////////////

/*
   For Explorer 16 board, here are the data and control signal definitions
   RS -> RB15
   E  -> RD4
   RW -> RD5
   DATA -> RE0 - RE7
*/

// Control signal data pins
#define RW LATDbits.LATD5  // LCD R/W signal
#define RS LATBbits.LATB15 // LCD RS signal
#define E LATDbits.LATD4   // LCD E signal

// Control signal pin direction
#define RW_TRIS TRISDbits.TRISD5
#define RS_TRIS TRISBbits.TRISB15
#define E_TRIS TRISDbits.TRISD4

// Data signals and pin direction
#define DATA LATE // Port for LCD data
#define DATAPORT PORTE
#define TRISDATA TRISE // I/O setup for data Port

/////////////////////
// definiciones posiciones cronometro
//////////////////////
#define posds 13
#define posseg 10
#define posmin 7