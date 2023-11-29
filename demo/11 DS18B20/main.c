#include <REGX52.H>
#include "DS18B20.h"
#include "LCD1602.h"


void Delay(unsigned int xms)		//@11.0592MHz
{
	unsigned char i, j;

	i = 2;
	j = 199;

	while(xms--){
		do
		{
			while (--j);
		} while (--i);
	}
}


void main()
{
	float t;
	
	LCD_Init();
	
	//LCD_ShowString(1,1,"Tempture:");
	
//	Delay(100);
//	DS18B20_ConverT();
//	t = DS18B20_ReadT();
//	LCD_ShowNum(2,1,(unsigned int)t,4);
//	LCD_ShowChar(2,4,'.');
//	LCD_ShowNum(2,5,(long)(t*1000)%1000,4);

	while(1)
	{
//		Delay(1000);
		DS18B20_ConverT();
		t = DS18B20_ReadT();
		LCD_ShowNum(2,1,t,3);
		LCD_ShowChar(2,4,'.');
		LCD_ShowNum(2,5,(long)(t*100)%100,3);		
	}
}
