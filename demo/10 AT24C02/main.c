#include <REGX52.H>
#include "AT24C02.h"
#include "LCD1602.h"


void main(){
	unsigned char Read_Data = 0x00;
	LCD_Init();
	//AT24C02_Write_Byte(0x00, 0x16);
	Read_Data = AT24C02_Read_Byte(0x00);
	LCD_ShowHexNum(1,1,Read_Data, 2);
	while(1){
	
	}
}
