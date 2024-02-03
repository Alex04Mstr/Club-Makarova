#include "main.h"
typedef unsigned char u8;
typedef unsigned char uint8_t;
//typedef int uint32_t;

#define Set_RS HAL_GPIO_WritePin(PORT_SIG,RS,SET)
#define Reset_RS HAL_GPIO_WritePin(PORT_SIG,RS,RESET)
#define Set_EN HAL_GPIO_WritePin(PORT_SIG,EN,SET)
#define Reset_EN HAL_GPIO_WritePin(PORT_SIG,EN,RESET)


#define Set_DB4 HAL_GPIO_WritePin(PORT_DATA,DB4,SET)
#define Reset_DB4 HAL_GPIO_WritePin(PORT_DATA,DB4,RESET)
#define Set_DB5 HAL_GPIO_WritePin(PORT_DATA,DB5,SET)
#define Reset_DB5 HAL_GPIO_WritePin(PORT_DATA,DB5,RESET)
#define Set_DB6 HAL_GPIO_WritePin(PORT_DATA,DB6,SET)
#define Reset_DB6 HAL_GPIO_WritePin(PORT_DATA,DB6,RESET)
#define Set_DB7 HAL_GPIO_WritePin(PORT_DATA,DB7,SET)
#define Reset_DB7 HAL_GPIO_WritePin(PORT_DATA,DB7,RESET)


#define PORT_SIG GPIOA
//#define PORT_SIG_RCC RCC_APB2Periph_GPIOB

#define RS L1_Pin
#define EN L2_Pin

#define PORT_DATA GPIOB
//#define PORT_DATA_RCC RCC_APB2Periph_GPIOC

#define DB4 L3_Pin
#define DB5 L4_Pin
#define DB6 L5_Pin
#define DB7 L6_Pin
///////////////////////////////////

typedef enum {
	COMMAND = 0,
	DATA = !COMMAND
	//DATA=1
} dat_or_comm;

typedef enum {
	LCD_DISABLE = 0,
	LCD_ENABLE = !LCD_DISABLE
} lcd_state;

typedef enum {
	CURSOR_DISABLE = 0,
	CURSOR_ENABLE = !CURSOR_DISABLE
} cursor_state;

typedef enum {
	NO_BLINK = 0,
	BLINK = !NO_BLINK
} cursor_mode;




void lcd_init(void);
void lcd_send(u8 byte, dat_or_comm dc);
void lcd_set_state(lcd_state state, cursor_state cur_state, cursor_mode cur_mode);
void lcd_clear(void);// ����������� ������ � ������ � ��������� ������!!!!!
void lcd_out(char * txt);
void lcd_set_xy(uint8_t x, uint8_t y);
void lcd_set_user_char(u8 char_num, u8 * char_data);
void lcd_delay(void);
void _delay_ms(int ms);
uint8_t Rus(char Val);


