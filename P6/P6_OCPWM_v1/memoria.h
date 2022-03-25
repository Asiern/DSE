
#define TAM_LINEA 16
#define N_LINEAS 10

// constantes y variables
extern const unsigned char Mens_LCD_1[16], Mens_LCD_2[16], Mens_LCD_3[16];
extern const unsigned char Mens_LCD_4[16], Mens_LCD_5[16], Mens_LCD_6[16], Mens_LCD_7[16], Mens_LCD_8[16];
extern unsigned char Ventana_LCD[N_LINEAS][TAM_LINEA];
extern unsigned char tabla_carac[16];

// funciones
void copiar_FLASH_RAM(const unsigned char *texto, unsigned int i);