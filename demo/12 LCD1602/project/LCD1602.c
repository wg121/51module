#include "LCD1602.h"

static void LCD_Delay()		//@11.0592MHz 1ms
{
	unsigned char i, j;

	i = 2;
	j = 199;
	do
	{
		while (--j);
	} while (--i);
}


/* 函数名称：
 *
 * 函数功能：向LCD1602发送一个指令
 *
 * 函数参数：发送的指令地址
 *
 * 函数返回值：void
 *
 * 备注：
 */
static void LCD1602_SendCommand(unsigned char Command)
{
	LCD_RS = 0;
	LCD_RW = 0;
	LCD_DATA_PORT = Command;
	LCD_E = 1;		//LCD_E下降沿执行
	LCD_Delay();
	LCD_E = 0;
	LCD_Delay();
}

/* 函数名称：LCD1602_SendData
 *
 * 函数功能：向LCD1602发送一个数据
 *
 * 函数参数：发送的数据
 *
 * 函数返回值：void
 *
 * 备注：
 */
static void LCD1602_SendData(unsigned char Data)
{
	LCD_RS = 1;
	LCD_RW = 0;
	LCD_DATA_PORT = Data;
	LCD_E = 1;		//LCD_E下降沿执行
	LCD_Delay();
	LCD_E = 0;
	LCD_Delay();
}

/* 函数名称：LCD_Init
 *
 * 函数功能：LCD1602初始化函数
 *
 * 函数参数：void
 *
 * 函数返回值：void
 *
 * 备注：
 */
void LCD_Init(void)
{
	LCD1602_SendCommand(0X38);
	LCD1602_SendCommand(0X0C);
	LCD1602_SendCommand(0X06);
	LCD1602_SendCommand(0X01);
}

/* 函数名称：LCD_ShowChar
 *
 * 函数功能：LCD1602发送一个字节函数
 *
 * 函数参数：Line：行
 *           Column：列
 *           Char：字符
 *
 * 函数返回值：void
 *
 * 备注：
 */
void LCD_ShowChar(unsigned char Line, unsigned char Column, unsigned char Char)
{
	if(Line == 1){
		LCD1602_SendCommand(0x80 | (Column - 1));
	}else{
		LCD1602_SendCommand(0x80 | (Column - 1) + 0x40);
	}
	
	LCD1602_SendData(Char);
}