
// Definiciones ligadas a la velocidad de transmision de UART2

#define Fosc 40000000                       // Frecuencia de reloj de la CPU (oscillator)
#define Fcy Fosc / 2                        // Velocidad de ejecucion de las instrucciones
#define BAUDRATE2 9600                      // Velocidad de transmision de UART2 (baudios)
#define T_1BIT_US (1000000 / BAUDRATE2) + 1 // Duracion de 1 bit

#define BAUD_RATEREG_2_BRGH1 ((Fcy / BAUDRATE2) / 4) - 1  // valor U2BRG si BRGH=1
#define BAUD_RATEREG_2_BRGH0 ((Fcy / BAUDRATE2) / 16) - 1 // valor U2BRG si BRGH=0

// Definiciones relacionadas con la pantalla del terminal del PC

#define clrscr "\x1b[2J" // 4 character: \x1b, [, 2, J
#define home "\x1b[H"    // 3 character: \x1b, [, H

#define CR 0x0D // carriage return
#define LF 0x0A // line feed
