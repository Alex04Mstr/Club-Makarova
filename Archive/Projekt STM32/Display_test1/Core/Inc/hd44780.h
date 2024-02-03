#include "main.h"
typedef unsigned char u8;
typedef unsigned char uint8_t;
//typedef int uint32_t;

#define Set_AO HAL_GPIO_WritePin(AO_GPIO_Port, AO_Pin, SET)
#define Reset_AO HAL_GPIO_WritePin(AO_GPIO_Port, AO_Pin, RESET)
#define Set_RW HAL_GPIO_WritePin(RW_GPIO_Port, RW_Pin, SET)
#define Reset_RW HAL_GPIO_WritePin(RW_GPIO_Port, RW_Pin, RESET)
#define Set_EN HAL_GPIO_WritePin(EN_GPIO_Port, EN_Pin, SET)
#define Reset_EN HAL_GPIO_WritePin(EN_GPIO_Port, EN_Pin, RESET)


#define Set_DB4 HAL_GPIO_WritePin(DB4_GPIO_Port, DB4_Pin, SET)
#define Reset_DB4 HAL_GPIO_WritePin(DB4_GPIO_Port, DB4_Pin, RESET)
#define Set_DB5 HAL_GPIO_WritePin(DB5_GPIO_Port, DB5_Pin, SET)
#define Reset_DB5 HAL_GPIO_WritePin(DB5_GPIO_Port, DB5_Pin, RESET)
#define Set_DB6 HAL_GPIO_WritePin(DB6_GPIO_Port, DB6_Pin, SET)
#define Reset_DB6 HAL_GPIO_WritePin(DB6_GPIO_Port, DB6_Pin, RESET)
#define Set_DB7 HAL_GPIO_WritePin(DB7_GPIO_Port, DB7_Pin, SET)
#define Reset_DB7 HAL_GPIO_WritePin(DB7_GPIO_Port, DB7_Pin, RESET)


//#define PORT_SIG GPIOA
//#define PORT_SIG_RCC RCC_APB2Periph_GPIOB

//#define AO GPIO_PIN_10
//#define EN GPIO_PIN_8

//#define PORT_DATA GPIOB
//#define PORT_DATA_RCC RCC_APB2Periph_GPIOC

//#define DB4 GPIO_PIN_9
//#define DB5 GPIO_PIN_7
//#define DB6 GPIO_PIN_6
//#define DB7 GPIO_PIN_7
///////////////////////////////////

typedef enum {
	COMMAND = 0,
	DATA = !COMMAND
	//DATA=0
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
void lcd_set_xyi(uint8_t x, uint8_t y);
void lcd_set_user_char(u8 char_num, u8 * char_data);
void lcd_delay(void);
void _delay_ms(int ms);
uint8_t Rus(char Val);


