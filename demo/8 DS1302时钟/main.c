#include <REGX52.H>
#include "DS1302.h"
#include "LCD1602.h"

void main()
{
	unsigned char Data = 0X00;
	DS1302_Init();	//初始化
	//DS1302_WriteByte(0X8E, 0X00);	//解除写保护
	LCD_Init();		//LCD1602初始化
	
	//测试:
	DS1302_WriteByte(WRITE_SECOND, 0x03);	//写操作，写秒为：03
	Data = DS1302_ReadByte(READ_SECOND);	//读操作，读秒数
	LCD_ShowChar(1,5,'a');
	LCD_ShowNum(1,1,Data,2);
	
	while(1)
	{
	
	}
}
