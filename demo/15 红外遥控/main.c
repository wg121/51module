#include <REGX52.H>
#include "delay.h"
#include "LCD1602.h"
#include "IR.h"

unsigned char Address;
unsigned char Command;


void main(){
	
	LCD_Init();
	IR_Init();
	
	while(1){
		if(IR_GetDataFlag() || IR_GetRepeatFlag()){		//接收到了数据,或者收到了repeat信号
			Address = IR_GetAddress();					//获取地址
			Command = IR_GetCommand();
			
			LCD_ShowHexNum(1,1,Address,2);
			LCD_ShowHexNum(2,1,Command,2);
		}
	}
}

