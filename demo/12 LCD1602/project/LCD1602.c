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


/* �������ƣ�
 *
 * �������ܣ���LCD1602����һ��ָ��
 *
 * �������������͵�ָ���ַ
 *
 * ��������ֵ��void
 *
 * ��ע��
 */
static void LCD1602_SendCommand(unsigned char Command)
{
	LCD_RS = 0;
	LCD_RW = 0;
	LCD_DATA_PORT = Command;
	LCD_E = 1;		//LCD_E�½���ִ��
	LCD_Delay();
	LCD_E = 0;
	LCD_Delay();
}

/* �������ƣ�LCD1602_SendData
 *
 * �������ܣ���LCD1602����һ������
 *
 * �������������͵�����
 *
 * ��������ֵ��void
 *
 * ��ע��
 */
static void LCD1602_SendData(unsigned char Data)
{
	LCD_RS = 1;
	LCD_RW = 0;
	LCD_DATA_PORT = Data;
	LCD_E = 1;		//LCD_E�½���ִ��
	LCD_Delay();
	LCD_E = 0;
	LCD_Delay();
}

/* �������ƣ�LCD_Init
 *
 * �������ܣ�LCD1602��ʼ������
 *
 * ����������void
 *
 * ��������ֵ��void
 *
 * ��ע��
 */
void LCD_Init(void)
{
	LCD1602_SendCommand(0X38);
	LCD1602_SendCommand(0X0C);
	LCD1602_SendCommand(0X06);
	LCD1602_SendCommand(0X01);
}

/* �������ƣ�LCD_ShowChar
 *
 * �������ܣ�LCD1602����һ���ֽں���
 *
 * ����������Line����
 *           Column����
 *           Char���ַ�
 *
 * ��������ֵ��void
 *
 * ��ע��
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