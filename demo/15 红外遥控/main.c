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
		if(IR_GetDataFlag() || IR_GetRepeatFlag()){		//���յ�������,�����յ���repeat�ź�
			Address = IR_GetAddress();					//��ȡ��ַ
			Command = IR_GetCommand();
			
			LCD_ShowHexNum(1,1,Address,2);
			LCD_ShowHexNum(2,1,Command,2);
		}
	}
}

