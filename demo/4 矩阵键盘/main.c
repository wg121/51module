#include <REGX52.H>
#include "LCD1602.h"
#include "MartixKey.h"
#include "Delay.h"

static unsigned int NUM[] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};

void Nixie(unsigned char Led, unsigned char Num){
		switch(Led){
			case 1: P2_4=1;P2_3=1;P2_2=1; break;
			case 2: P2_4=1;P2_3=1;P2_2=0; break;
			case 3: P2_4=1;P2_3=0;P2_2=1; break;
			case 4: P2_4=1;P2_3=0;P2_2=0; break;
			case 5: P2_4=0;P2_3=1;P2_2=1; break;
			case 6: P2_4=0;P2_3=1;P2_2=0; break;
			case 7: P2_4=0;P2_3=0;P2_2=1; break;
			case 8: P2_4=0;P2_3=0;P2_2=0; break;
			default : break;
		}
		P0 = NUM[Num];
		Delay(1);
		P0 = 0X00;
}

void main(){
	unsigned char Num = 0, G = 0, S = 0;
	//LCD_Init();
	
	while(1){
		Num = matrixKey();
		G = Num % 10;
		S = Num / 10;
		Nixie(1, S);
		Nixie(2, G);
	}
}
