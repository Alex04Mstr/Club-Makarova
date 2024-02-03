#include "main.h"
typedef unsigned char u8;
typedef unsigned char uint8_t;

#define LCD_CLEARDISPLAY 0x01
#define LCD_RETURNHOME 0x02
#define LCD_ENTRYMODESET 0x04
#define LCD_DISPLAYCONTROL 0x08
#define LCD_CURSORSHIFT 0x10
#define LCD_FUNCTIONSET 0x20
#define LCD_SETCGRAMADDR 0x40
#define LCD_SETDDRAMADDR 0x80

// flags for display entry mode
#define LCD_ENTRYRIGHT 0x00
#define LCD_ENTRYLEFT 0x02
#define LCD_ENTRYSHIFTINCREMENT 0x01
#define LCD_ENTRYSHIFTDECREMENT 0x00

// flags for display on/off control
#define LCD_DISPLAYON 0x04
#define LCD_DISPLAYOFF 0x00
#define LCD_CURSORON 0x02
#define LCD_CURSOROFF 0x00
#define LCD_BLINKON 0x01
#define LCD_BLINKOFF 0x00

// flags for display/cursor shift
#define LCD_DISPLAYMOVE 0x08
#define LCD_CURSORMOVE 0x00
#define LCD_MOVERIGHT 0x04
#define LCD_MOVELEFT 0x00

// flags for function set
#define LCD_8BITMODE 0x10
#define LCD_4BITMODE 0x00
#define LCD_2LINE 0x08
#define LCD_1LINE 0x00
#define LCD_5x10DOTS 0x04
#define LCD_5x8DOTS 0x00

// flags for backlight control
#define LCD_BACKLIGHT 0x08
#define LCD_NOBACKLIGHT 0x00

// set pins
#define Set_AO HAL_GPIO_WritePin(AO_GPIO_Port, AO_Pin, SET)
#define Set_EN HAL_GPIO_WritePin(EN_GPIO_Port, EN_Pin, SET)

// reset pins
#define Reset_AO HAL_GPIO_WritePin(AO_GPIO_Port, AO_Pin, RESET)
#define Reset_EN HAL_GPIO_WritePin(EN_GPIO_Port, EN_Pin, RESET)

typedef enum {
	COMMAND = 0,
	DATA = !COMMAND
	//DATA=1
} dat_or_comm;

typedef enum {
	BIT4 = 0,
	BIT8 = !BIT4
	//BIT8 = 1
} b8_or_b4;

void lcdBitMode(b8_or_b4 bob);
void lcdInit();
void lcdClear(void);
void sendCmd(char cmd);
void sendData(char dt);
void lcdWrite (char* str);
void lcd8bitSend(u8 byte);
void lcd4bitSend(u8 byte);
void lcdSend(u8 byte);
void EnSend(void);
void setCursor(char x, char y);
void cursorOn(void);
void blinkOn(void);
uint8_t Rus(char Val);


