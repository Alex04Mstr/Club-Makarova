#include "stm32f0xx_hal.h"
#include "hd44780.h"

extern TIM_HandleTypeDef htim3;
int strlen (char*p)
     { int i=0;
     while( *p++ ) i++;
     return i;//отлажено
     }
void _delay_ms(int ms)
{

  HAL_Delay(ms);
}
void _delay_us(int us)
{

	HAL_TIM_Base_Start(&htim3);
	__HAL_TIM_SET_COUNTER(&htim3,0);
	while(__HAL_TIM_GET_COUNTER(&htim3) < us);
	HAL_TIM_Base_Stop(&htim3);
}

void lcd_init(void) {

	_delay_ms(30);
		//GPIO_ResetBits(PORT_SIG, EN); // E V
	    Set_EN;
		//GPIO_ResetBits(PORT_SIG, RS);
	    Reset_AO;
		//GPIO_ResetBits(PORT_SIG, RW);
	    Reset_RW;
		//GPIO_ResetBits(PORT_DATA, DB6);
	    Reset_DB6;
		//GPIO_ResetBits(PORT_DATA, DB7);
	    Reset_DB7;
		//GPIO_SetBits(PORT_DATA, DB4);
	    Set_DB4;
		//GPIO_SetBits(PORT_DATA, DB5);
	    Set_DB5;
		//GPIO_SetBits(PORT_SIG, EN); // E ^
	    Reset_EN;

		_delay_us(50);
		//GPIO_ResetBits(PORT_SIG, EN); // E V
		Set_EN;
		//GPIO_ResetBits(PORT_SIG, RS);
		Reset_AO;
		//GPIO_ResetBits(PORT_SIG, RW);
		Reset_RW;
		//GPIO_ResetBits(PORT_DATA, DB6);
		Reset_DB6;
		//GPIO_ResetBits(PORT_DATA, DB7);
		Reset_DB7;
		//GPIO_SetBits(PORT_DATA, DB4);
		Set_DB4;
		//GPIO_SetBits(PORT_DATA, DB5);
		Set_DB5;
		//GPIO_SetBits(PORT_SIG, EN); // E ^
		Reset_EN;

		_delay_us(50); //more 100us
		//GPIO_ResetBits(PORT_SIG, EN); // E V
		Set_EN;
		//GPIO_ResetBits(PORT_SIG, RS);
		Reset_AO;
		//GPIO_ResetBits(PORT_SIG, RW);
		Reset_RW;
		//GPIO_ResetBits(PORT_DATA, DB6);
		Reset_DB6;
		//GPIO_ResetBits(PORT_DATA, DB7);
		Reset_DB7;
		//GPIO_SetBits(PORT_DATA, DB4);
		Set_DB4;
		//GPIO_SetBits(PORT_DATA, DB5);
		Set_DB5;
		//GPIO_SetBits(PORT_SIG, EN); // E ^
		Reset_EN;

		_delay_us(50);
		//GPIO_ResetBits(PORT_SIG, EN); // E V
		Set_EN;
		//GPIO_ResetBits(PORT_SIG, RS);
		Reset_AO;
		//GPIO_ResetBits(PORT_SIG, RW);
		Reset_RW;
		//GPIO_ResetBits(PORT_DATA, DB6);
		Reset_DB6;
		//GPIO_ResetBits(PORT_DATA, DB7);
		Reset_DB7;
		//GPIO_ResetBits(PORT_DATA, DB4);
		Reset_DB4;
		//GPIO_SetBits(PORT_DATA, DB5);
		Set_DB5;
		//GPIO_SetBits(PORT_SIG, EN); // E ^
		Reset_EN;

		_delay_us(50);
		//GPIO_ResetBits(PORT_SIG, EN); // E V
		Set_EN;
		//GPIO_ResetBits(PORT_SIG, RS);
		Reset_AO;
		//GPIO_ResetBits(PORT_SIG, RW);
		Reset_RW;
		//GPIO_ResetBits(PORT_DATA, DB6);
		Reset_DB6;
		//GPIO_ResetBits(PORT_DATA, DB7);
		Reset_DB7;
		//GPIO_ResetBits(PORT_DATA, DB4);
		Reset_DB4;
		//GPIO_SetBits(PORT_DATA, DB5);
		Set_DB5;
		//GPIO_SetBits(PORT_SIG, EN); // E ^
		Reset_EN;

		_delay_us(50);
		//GPIO_ResetBits(PORT_SIG, EN); // E V
		Set_EN;
		//GPIO_ResetBits(PORT_SIG, RS);
		Reset_AO;
		//GPIO_ResetBits(PORT_SIG, RW);
		Reset_RW;
		//GPIO_ResetBits(PORT_DATA, DB6);
		Reset_DB6;
		//GPIO_ResetBits(PORT_DATA, DB5);
		Reset_DB5;
		//GPIO_ResetBits(PORT_DATA, DB4);
		Reset_DB4;
		//GPIO_SetBits(PORT_DATA, DB7);
		Set_DB7;
		//GPIO_SetBits(PORT_SIG, EN); // E ^
		Reset_EN;

		_delay_us(50);
		//GPIO_ResetBits(PORT_SIG, EN); // E V
		Set_EN;
		//GPIO_ResetBits(PORT_SIG, RS);
		Reset_AO;
		//GPIO_ResetBits(PORT_SIG, RW);
		Reset_RW;
		//GPIO_ResetBits(PORT_DATA, DB6);
		Reset_DB6;
		//GPIO_ResetBits(PORT_DATA, DB7);
		Reset_DB7;
		//GPIO_ResetBits(PORT_DATA, DB4);
		Reset_DB4;
		//GPIO_ResetBits(PORT_DATA, DB5);
		Reset_DB5;
		//GPIO_SetBits(PORT_SIG, EN); // E ^
		Reset_EN;

		_delay_us(50);
		//GPIO_ResetBits(PORT_SIG, EN); // E V
		Set_EN;
		//GPIO_ResetBits(PORT_SIG, RS);
		Reset_AO;
		//GPIO_ResetBits(PORT_SIG, RW);
		Reset_RW;
		//GPIO_ResetBits(PORT_DATA, DB6);
		Reset_DB6;
		//GPIO_ResetBits(PORT_DATA, DB7);
		Set_DB7;
		//GPIO_ResetBits(PORT_DATA, DB5);
		Reset_DB5;
		//GPIO_SetBits(PORT_DATA, DB4);
		Reset_DB4;
		//GPIO_SetBits(PORT_SIG, EN); // E ^
		Reset_EN;

		_delay_us(50);
		//GPIO_ResetBits(PORT_SIG, EN); // E V
		Set_EN;
		//GPIO_ResetBits(PORT_SIG, RS);
		Reset_AO;
		//GPIO_ResetBits(PORT_SIG, RW);
		Reset_RW;
		//GPIO_ResetBits(PORT_DATA, DB6);
		Reset_DB6;
		//GPIO_ResetBits(PORT_DATA, DB7);
		Reset_DB7;
		//GPIO_ResetBits(PORT_DATA, DB5);
		Reset_DB5;
		//GPIO_ResetBits(PORT_DATA, DB4);
		Reset_DB4;
		//GPIO_SetBits(PORT_SIG, EN); // E ^
		Reset_EN;

		_delay_us(50);
		//GPIO_ResetBits(PORT_SIG, EN); // E V
		Set_EN;
		//GPIO_ResetBits(PORT_SIG, RS);
		Reset_AO;
		//GPIO_ResetBits(PORT_SIG, RW);
		Reset_RW;
		//GPIO_SetBits(PORT_DATA, DB6);
		Reset_DB6;
		//GPIO_SetBits(PORT_DATA, DB7);
		Reset_DB7;
		//GPIO_SetBits(PORT_DATA, DB5);
		Reset_DB5;
		//GPIO_SetBits(PORT_DATA, DB4);
		Set_DB4;
		//GPIO_SetBits(PORT_SIG, EN); // E ^
		Reset_EN;

		_delay_us(50);
		//GPIO_ResetBits(PORT_SIG, EN); // E V
		Set_EN;
		//GPIO_ResetBits(PORT_SIG, EN); // E V
		Reset_EN;
		//GPIO_SetBits(PORT_SIG, RS);
		Reset_AO;
		//GPIO_ResetBits(PORT_SIG, RW);
		Reset_RW;
		//GPIO_ResetBits(PORT_DATA, DB6);
		Reset_DB6;
		//GPIO_ResetBits(PORT_DATA, DB7);
		Reset_DB7;
		//GPIO_ResetBits(PORT_DATA, DB5);
		Reset_DB5;
		//GPIO_ResetBits(PORT_DATA, DB4);
		Reset_DB4;
		//GPIO_SetBits(PORT_SIG, EN); // E ^
		Reset_EN;

		_delay_us(50);

		//GPIO_ResetBits(PORT_SIG, EN); // E V
		Set_EN;
		//GPIO_SetBits(PORT_SIG, RS);
		Reset_AO;
		//GPIO_ResetBits(PORT_SIG, RW);
		Reset_RW;
		//GPIO_ResetBits(PORT_DATA, DB6);
		Set_DB6;
		//GPIO_ResetBits(PORT_DATA, DB7);
		Reset_DB7;
		//GPIO_ResetBits(PORT_DATA, DB5);
		Set_DB5;
		//GPIO_ResetBits(PORT_DATA, DB4);
		Reset_DB4;
		//GPIO_SetBits(PORT_SIG, EN); // E ^
		Reset_EN;

	_delay_us(50);
	lcd_set_state(LCD_ENABLE,CURSOR_DISABLE,NO_BLINK);
	lcd_clear();
	lcd_send(0x06,COMMAND);
}

void lcd_set_user_char(uint8_t char_num, uint8_t * char_data) {
	uint8_t i;
	lcd_send(((1<<6) | (char_num * 8) ), COMMAND);
	for (i=0;i<=7;i++) {
		lcd_send(char_data[i],DATA);
	}
	lcd_send((1<<7), COMMAND);
}

void lcd_set_xyi(uint8_t x, uint8_t y)  {

		lcd_send( (((((y)&1)*0x40)+((((y)&3)>>1)*0x14)+(x))|128),COMMAND);

}



void lcd_clear(void) {
	lcd_send(0x01,COMMAND);
	_delay_ms(2);
}

void lcd_set_state(lcd_state state, cursor_state cur_state, cursor_mode cur_mode)  {
	if (state==LCD_DISABLE)  {
		lcd_send(0x08,COMMAND);
	} else {
		if (cur_state==CURSOR_DISABLE) {
			if (cur_mode==NO_BLINK)  {
				lcd_send(0x0C,COMMAND);
			} else {
				lcd_send(0x0D,COMMAND);
			}
		} else  {
			if (cur_mode==NO_BLINK)  {
				lcd_send(0x0E,COMMAND);
			} else {
				lcd_send(0x0F,COMMAND);
			}
		}
	}
}
/*
static void fallingEdge(void) {
    Reset_EN;
    Set_EN;
    Reset_EN;

    HAL_Delay(1);
}
static void send4Bits(char data) {
		if(data&0x01) Set_DB4;
		if(data&0x02) Set_DB5;
		if(data&0x04) Set_DB6;
		if(data&0x08) Set_DB7;

		fallingEdge();
	}
*/
void lcd_send(uint8_t byte, dat_or_comm dc)  {

	//GPIO_ResetBits(PORT_DATA, DB7 | DB6 | DB5 | DB4);
		Reset_DB7;
		Reset_DB6;
		Reset_DB5;
		Reset_DB4;
		//GPIO_ResetBits(PORT_SIG, RS | EN);
		Reset_AO;
		Set_EN;

	//LCD_PORT->BSRR=(LCD_DB7_BC | LCD_DB6_BC | LCD_DB5_BC | LCD_DB4_BC | LCD_CD_BC | LCD_EN_BC);

	if (dc) {
		//GPIO_SetBits(PORT_SIG, RS);
		Set_AO;
		//LCD_PORT->BSRR=LCD_CD_BS;
	}


	if (byte & 0x10) {
		//GPIO_SetBits(PORT_DATA, DB4);
		Set_DB4;
		//LCD_PORT->BSRR=LCD_DB4_BS;
	}
	if (byte & 0x20) {
		//GPIO_SetBits(PORT_DATA, DB5);
		Set_DB5;
		//LCD_PORT->BSRR=LCD_DB5_BS;
	}
	if (byte & 0x40) {
		//GPIO_SetBits(PORT_DATA, DB6);
		Set_DB6;
		//LCD_PORT->BSRR=LCD_DB6_BS;
	}
	if (byte & 0x80) {
		//GPIO_SetBits(PORT_DATA, DB7);
		Set_DB7;
		//LCD_PORT->BSRR=LCD_DB7_BS;
	}

	//GPIO_SetBits(PORT_SIG, EN);
	Set_EN;
	//LCD_PORT->BSRR=LCD_EN_BS;
	_delay_ms(1);
	//GPIO_ResetBits(PORT_SIG, EN);
	Reset_EN;
	//LCD_PORT->BSRR=LCD_EN_BC;
	_delay_us(40);


	//GPIO_ResetBits(PORT_DATA, DB7 | DB6 | DB5 | DB4);
			Reset_DB7;
			Reset_DB6;
			Reset_DB5;
			Reset_DB4;
	//LCD_PORT->BSRR=(LCD_DB7_BC | LCD_DB6_BC | LCD_DB5_BC | LCD_DB4_BC );

	if (byte & 0x01) {
		//GPIO_SetBits(PORT_DATA, DB4);
		Set_DB4;
		//LCD_PORT->BSRR=LCD_DB4_BS;
	}
	if (byte & 0x02) {
		//GPIO_SetBits(PORT_DATA, DB5);
		Set_DB5;
		//LCD_PORT->BSRR=LCD_DB5_BS;
	}
	if (byte & 0x04) {
		//GPIO_SetBits(PORT_DATA, DB6);
		Set_DB6;
		//LCD_PORT->BSRR=LCD_DB6_BS;
	}
	if (byte & 0x08) {
		//GPIO_SetBits(PORT_DATA, DB7);
		Set_DB7;
		//LCD_PORT->BSRR=LCD_DB7_BS;
	}

	//GPIO_SetBits(PORT_SIG, EN);
	Set_EN;
	//LCD_PORT->BSRR=LCD_EN_BS;
	_delay_us(2);
	//GPIO_ResetBits(PORT_SIG, EN);
	Reset_EN;
	//LCD_PORT->BSRR=LCD_EN_BC;
	_delay_us(40);


}

uint8_t Rus(char Val)
{


	switch(Val)
	{
	case 'А':
		return 0x41;//
		break;
	case 'а':
		return 0x61;//
		break;
	case 'Б':
		return 0xA0;//
		break;
	case 'б':
		return 0xB2;//
		break;
	case 'В':
		return 0x42;//
		break;
	case 'в':
		return 0xB3;//
		break;
	case 'Г':
		return 0xA1;//
		break;
	case 'г':
		return 0xB4;//
		break;
	case 'Д':
		return 0xE0;//
		break;
	case 'д':
			return 0xE3;//
			break;
	case 'Е':
		return 0x45;//
		break;
	case 'е':
		return 0x65;//
		break;
	case 'Ё':
		return 0xA2;//
		break;
	case 'ё':
		return 0xB5;//
		break;
	case 'Ж':
		return 0xA3;//
		break;
	case 'ж':
		return 0xB6;//
		break;
	case 'З':
		return 0xA4;//
		break;
	case 'з':
		return 0xB7;//
		break;
	case 'И':
		return 0xA5;//
		break;
	case 'и':
		return 0xB8;//
		break;
	case 'Й':
		return 0xA6;//
		break;
	case 'й':
		return 0xB9;//
		break;
	case 'К':
		return 0x4B;//
		break;
	case 'к':
		return 0xBA;//
		break;
	case 'Л':
		return 0xA7;//
		break;
	case 'л':
		return 0xBB;//
			break;
		case 'М':
			return 0x4D;//
			break;
		case 'м':
			return 0xBC;//
			break;
		case 'Н':
			return 0x48;//
			break;
		case 'н':
			return 0xBD;//
			break;
		case 'О':
			return 0x4F;//
			break;
		case 'о':
			return 0x6F;//
			break;
		case 'П':
			return 0xA8;//
			break;
		case 'п':
			return 0xBE;//
				break;
			case 'Р':
				return 0x50;//
				break;
			case 'р':
				return 0x70;//
				break;
			case 'С':
				return 0x43;//
				break;
			case 'с':
				return 0x63;//
				break;
			case 'Т':
				return 0x54;//
				break;
			case 'т':
				return 0xBF;//
				break;
			case 'У':
				return 0xA9;//
				break;
			case 'у':
				return 0x79;//
				break;
			case 'Ф':
				return 0xAA;//
				break;
			case 'ф':
				return 0xE4;//
				break;
			case 'Х':
				return 0x58;//
				break;
			case 'х':
				return 0x78;//
				break;
			case 'Ц':
				return 0xE1;//
				break;
			case 'ц':
				return 0xE5;//
				break;
			case 'Ч':
				return 0xAB;//
				break;
			case 'ч':
				return 0xC0;//
				break;
			case 'Ш':
				return 0xAC;//
				break;
			case 'ш':
				return 0xC1;//
				break;
			case 'Щ':
				return 0xE2;//
				break;
			case 'щ':
				return 0xE6;//
				break;
			case 'Ъ':
				return 0xAD;//
				break;
			case 'ъ':
				return 0xC2;//
				break;
			case 'Ы':
				return 0xAE;//
				break;
			case 'ы':
				return 0xC3;//
				break;
			case 'Ь':
				return 0xC4;//
				break;
			case 'ь':
				return 0xC4;//
				break;
			case 'Э':
				return 0xAF;//
				break;
			case 'э':
				return 0xC5;//
				break;
			case 'Ю':
				return 0xB0;//
				break;
			case 'ю':
				return 0xC6;//
				break;
			case 'Я':
				return 0xB1;//
				break;
			case 'я':
				return 0xC7;//
				break;
			default:
				return Val;
				break;
	}
}
void lcd_out(char * txt) {
	for(int i=0;i<strlen(txt);i++) {
			lcd_send(Rus(txt[i]),DATA);
		}
}

