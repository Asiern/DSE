/* Funciones para trabajar con el modulo UART2
================================================
Comentarios!!!!!!!!!!!
Autorxs:
Fecha:
*/

#include "p24HJ256GP610A.h"
#include "timers.h"
#include "commons.h"
#include "memoria.h"
#include "globals.h"

// Estados utilizados en la rutina de atencion del UART
enum
{
	L1,			 // Estado de escritura en la linea1
	L2,			 // Estado de escritura en la linea2
	HOME,		 // Estado de mover el cursor a la posicion inicial
	JP			 // Estado de escritura de salto de linea
} estado = HOME; // Estado inicial L1

int TPos = 0; // Posicion del caracter a enviar por UART de la ventanaLCD

void inic_UART2()
{

	// Velocidad de transmision
	// Hay que hacer solo una de las dos asignaciones siguientes
	// U2BRG = BAUD_RATEREG_2_BRGH1;
	U2BRG = BAUD_RATEREG_2_BRGH0;

	// U2MODE: habilitar el modulo (UARTEN), 8 bits, paridad par (PDSEL),
	// 1 bit de stop (STSEL), BRGH ...
	U2MODE = 0;
	U2MODEbits.PDSEL1 = 1; // Paridad par

	// U2STA: modo de interrupcion en el envio (UTXISEL), habilitacion del
	// envio (UTXEN), modo de interrupcion en la recepcion (URXISEL)
	U2STA = 0;

	// inicializacion de los bits IE e IF relacionados (IP si se quiere modificar)
	IFS1bits.U2RXIF = 0;
	IFS1bits.U2TXIF = 0;
	IEC1bits.U2RXIE = 1;
	IEC1bits.U2TXIE = 1;

	// IPC7bits.U2RXIP=xx;
	// IPC7bits.U2TXIP=xx;

	// interrupciones debidas a errores + bug
	IEC4bits.U2EIE = 0;
	U2STAbits.OERR = 0;

	// Habilitar el modulo y la linea TX.
	// Siempre al final y en ese orden!!!

	U2MODEbits.UARTEN = 1; // habilitar UART2
	U2STAbits.UTXEN = 1;   // habilitar transmision tras habilitar modulo

	Delay_us(T_1BIT_US); // Esperar tiempo de 1 bit
	U2TXREG = 0;
}

void put_UART2(char c)
// Envio de un dato mediante UART2 por ENCUESTA
{
	U2TXREG = c;
	while (!IFS1bits.U2TXIF)
		;
	IFS1bits.U2TXIF = 0;
}

void home_UART()
{
	put_UART2(home[0]);
	put_UART2(home[1]);
	put_UART2(home[2]);
}

char get_UART2()
// Recepcion de un dato mediante UART2 por ENCUESTA
{
	while (!IFS1bits.U2RXIF)
		;
	IFS1bits.U2RXIF = 0;
	return (U2RXREG); // La funcion devuelve el dato recibido
}

void enviar_UART2_ventana()
// Envio de la informacion de Ventana_LCD
{
	int i, j;
	for (i = 0; i < N_LINEAS; i++)
	{
		for (j = 0; j < TAM_LINEA; j++)
			put_UART2(Ventana_LCD[i][j]);
		put_UART2(CR);
		put_UART2(LF);
	}
}

void recibir_teclas(unsigned char num)
// Recibe mediante la UART2 tantos datos como indique el parametro num
// Los guarda en Ventana_LCD para que se visualicen en la pantalla LCD
{
	int i = 0;

	while (i < num)
	{
		Ventana_LCD[0][i] = get_UART2();
		i++;
	}
}

void _ISR_NO_PSV _U2RXInterrupt()
{
	switch (U2RXREG)
	{
	case 'p':
		T7CONbits.TON = 0; // Deshabilitar interrupciones del Temporizador T7
		flag = 0;
		break;
	case 'c':
		T7CONbits.TON = 1; // Habilitar interrupciones del Temporizador T7
		flag = 0;
		break;
	case 'i': // Resetear Temporizador T7
		flag = 0;
		reset = 1;
		TMR7 = 0;
		break;
	default:
		break;
	}
	IFS1bits.U2RXIF = 0;
}

/**
 * Funcion para atender a las interrupciones del UART
 *
 * Mediante una máquina de estados (con los estados definidos en el enum llamado estado),
 * gestionamos el envio de caracteres por UART para la correcta visualización.
 *
 * En los estados L1 y L2, escribimos en su línea correspondiente
 * Mediante el estado JP, escribimos el salto de línea.
 * Mediante el estado HOME, movemos el cursor al principio
 *
 * Se utiliza la variable TPos para indicar la posición en la que está escribiendo
 */
void _ISR_NO_PSV _U2TXInterrupt()
{
	switch (estado)
	{
	case L1:
		U2TXREG = Ventana_LCD[0][TPos];
		if (TPos == 15)
		{
			estado = JP;
			TPos = 0;
		}
		else
			TPos++;
		break;
	case JP:
		if (TPos == 1)
		{
			estado = L2;
			TPos = 0;
			U2TXREG = LF;
		}
		else
		{
			TPos++;
			U2TXREG = CR;
		}
		break;
	case L2:
		U2TXREG = Ventana_LCD[1][TPos];
		if (TPos == 15)
		{
			estado = HOME;
			TPos = 0;
		}
		else
			TPos++;
		break;
	case HOME:
		U2TXREG = home[TPos];
		if (TPos == 2)
		{
			TPos = 0;
			estado = L1;
		}
		else
			TPos++;
		break;
	default:
		break;
	}
	IFS1bits.U2TXIF = 0;
}