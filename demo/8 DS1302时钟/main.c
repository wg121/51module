#include <REGX52.H>
#include "DS1302.h"
#include "LCD1602.h"

void main()
{
	unsigned char Data = 0X00;
	DS1302_Init();	//��ʼ��
	//DS1302_WriteByte(0X8E, 0X00);	//���д����
	LCD_Init();		//LCD1602��ʼ��
	
	//����:
	DS1302_WriteByte(WRITE_SECOND, 0x03);	//д������д��Ϊ��03
	Data = DS1302_ReadByte(READ_SECOND);	//��������������
	LCD_ShowChar(1,5,'a');
	LCD_ShowNum(1,1,Data,2);
	
	while(1)
	{
	
	}
}
