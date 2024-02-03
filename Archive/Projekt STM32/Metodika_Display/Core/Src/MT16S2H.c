#include "MT-16S2H.h"
//#include < string.h >
char dispSet;
uint8_t bitMode;

void lcdBitMode(b8_or_b4 bob) // ������������� �����������
{
	if(bob) bitMode = 1;
	else bitMode = 0;
}

void lcdInit(void) // ������������� ���
{
	Reset_EN;
	Reset_AO;
	HAL_Delay(50);

	if(bitMode) // ���� ����������� 8 ���+
	{
		dispSet = LCD_8BITMODE | LCD_2LINE | LCD_5x8DOTS;
		sendCmd(LCD_FUNCTIONSET | dispSet);
		HAL_Delay(5);
		sendCmd(LCD_FUNCTIONSET | dispSet);
		HAL_Delay(5);
		sendCmd(LCD_FUNCTIONSET | dispSet);
		HAL_Delay(5);
	}
	else // ����������� 4 ����
	{
		dispSet = LCD_4BITMODE | LCD_2LINE | LCD_5x8DOTS;
		lcd4bitSend(0x03);
		HAL_Delay(5);
		lcd4bitSend(0x03);
		HAL_Delay(5);
		lcd4bitSend(0x03);
		HAL_Delay(2);
		lcd4bitSend(0x02);
		HAL_Delay(2);
	}

	sendCmd(LCD_FUNCTIONSET | dispSet);
	dispSet = LCD_DISPLAYON | LCD_CURSOROFF | LCD_BLINKOFF;
	sendCmd(LCD_DISPLAYCONTROL | dispSet);
	HAL_Delay(2);

	lcdClear();
	dispSet =  LCD_ENTRYLEFT | LCD_ENTRYSHIFTDECREMENT;
	sendCmd(LCD_ENTRYMODESET | dispSet);
	HAL_Delay(2);
}

void lcdClear(void) // ������� �������
{
	sendCmd(LCD_CLEARDISPLAY);
	HAL_Delay(5);
}

void sendCmd(char cmd) // �������� �������
{
	Reset_AO;
	lcdSend(cmd);
}

void sendData(char dt) // �������� ������
{
	Set_AO;
	lcdSend(dt);
}

void lcdWrite (char* str) // �������� ������
{
	for(; *str != 0; ++str)
	{
		sendData(Rus(*str));
	}
}

void lcdWriteNum(uint32_t num)
{

}

void lcd8bitSend(u8 byte) // �������� �������� ��� 8-������ �����������
{
	HAL_GPIO_WritePin(DB0_GPIO_Port, DB0_Pin, (byte & 0x01));
	HAL_GPIO_WritePin(DB1_GPIO_Port, DB1_Pin, (byte & 0x02));
	HAL_GPIO_WritePin(DB2_GPIO_Port, DB2_Pin, (byte & 0x04));
	HAL_GPIO_WritePin(DB3_GPIO_Port, DB3_Pin, (byte & 0x08));
	HAL_GPIO_WritePin(DB4_GPIO_Port, DB4_Pin, (byte & 0x10));
	HAL_GPIO_WritePin(DB5_GPIO_Port, DB5_Pin, (byte & 0x20));
	HAL_GPIO_WritePin(DB6_GPIO_Port, DB6_Pin, (byte & 0x40));
	HAL_GPIO_WritePin(DB7_GPIO_Port, DB7_Pin, (byte & 0x80));

	EnSend();
}

void lcd4bitSend(u8 byte) // �������� �������� ��� 4-������ �����������
{
	HAL_GPIO_WritePin(DB4_GPIO_Port, DB4_Pin, (byte & 0x01));
	HAL_GPIO_WritePin(DB5_GPIO_Port, DB5_Pin, (byte & 0x02));
	HAL_GPIO_WritePin(DB6_GPIO_Port, DB6_Pin, (byte & 0x04));
	HAL_GPIO_WritePin(DB7_GPIO_Port, DB7_Pin, (byte & 0x08));
	EnSend();
}

void lcdSend(u8 byte) // �������� ������ � ����������� �� �����������
{
	if(bitMode) lcd8bitSend(byte);
	else
	{
		lcd4bitSend(byte >> 4);
		lcd4bitSend(byte);
	}
}

void EnSend(void) // ������������� �������� �������
{
	Set_EN;
	Reset_EN;
	Set_EN;
	HAL_Delay(1);
}

void setCursor(char x, char y) // ��������� ��������� �������
{

	uint8_t base = 0;

	if(y==1) {
		base = 0x40;
	}
	else {
		base = 0;
	}

	sendCmd( 0x80 | (base + x));


}

void cursorOn(void) // ����������� �������
{
	sendCmd(0x08 | 0x04 | 0x02);
}

void blinkOn(void) // �������� �������
{
	sendCmd(0x08 | 0x04 | 0x01);
}

uint8_t Rus(char Val) // ��������� �������� � ������� ���������
{


	switch(Val)
	{
	case '�':
		return 0x41;//
		break;
	case '�':
		return 0x61;//
		break;
	case '�':
		return 0xA0;//
		break;
	case '�':
		return 0xB2;//
		break;
	case '�':
		return 0x42;//
		break;
	case '�':
		return 0xB3;//
		break;
	case '�':
		return 0xA1;//
		break;
	case '�':
		return 0xB4;//
		break;
	case '�':
		return 0xE0;//
		break;
	case '�':
			return 0xE3;//
			break;
	case '�':
		return 0x45;//
		break;
	case '�':
		return 0x65;//
		break;
	case '�':
		return 0xA2;//
		break;
	case '�':
		return 0xB5;//
		break;
	case '�':
		return 0xA3;//
		break;
	case '�':
		return 0xB6;//
		break;
	case '�':
		return 0xA4;//
		break;
	case '�':
		return 0xB7;//
		break;
	case '�':
		return 0xA5;//
		break;
	case '�':
		return 0xB8;//
		break;
	case '�':
		return 0xA6;//
		break;
	case '�':
		return 0xB9;//
		break;
	case '�':
		return 0x4B;//
		break;
	case '�':
		return 0xBA;//
		break;
	case '�':
		return 0xA7;//
		break;	case '�':
			return 0xBB;//
			break;
		case '�':
			return 0x4D;//
			break;
		case '�':
			return 0xBC;//
			break;
		case '�':
			return 0x48;//
			break;
		case '�':
			return 0xBD;//
			break;
		case '�':
			return 0x4F;//
			break;
		case '�':
			return 0x6F;//
			break;
		case '�':
			return 0xA8;//
			break;	case '�':
				return 0xBE;//
				break;
			case '�':
				return 0x50;//
				break;
			case '�':
				return 0x70;//
				break;
			case '�':
				return 0x43;//
				break;
			case '�':
				return 0x63;//
				break;
			case '�':
				return 0x54;//
				break;
			case '�':
				return 0xBF;//
				break;
			case '�':
				return 0xA9;//
				break;
			case '�':
				return 0x79;//
				break;
			case '�':
				return 0xAA;//
				break;
			case '�':
				return 0xE4;//
				break;
			case '�':
				return 0x58;//
				break;
			case '�':
				return 0x78;//
				break;
			case '�':
				return 0xE1;//
				break;
			case '�':
				return 0xE5;//
				break;
			case '�':
				return 0xAB;//
				break;
			case '�':
				return 0xC0;//
				break;
			case '�':
				return 0xAC;//
				break;
			case '�':
				return 0xC1;//
				break;
			case '�':
				return 0xE2;//
				break;
			case '�':
				return 0xE6;//
				break;
			case '�':
				return 0xAD;//
				break;
			case '�':
				return 0xC2;//
				break;
			case '�':
				return 0xAE;//
				break;
			case '�':
				return 0xC3;//
				break;
			case '�':
				return 0xC4;//
				break;
			case '�':
				return 0xC4;//
				break;
			case '�':
				return 0xAF;//
				break;
			case '�':
				return 0xC5;//
				break;
			case '�':
				return 0xB0;//
				break;
			case '�':
				return 0xC6;//
				break;
			case '�':
				return 0xB1;//
				break;
			case '�':
				return 0xC7;//
				break;
			default:
				return Val;
				break;
	}
}
