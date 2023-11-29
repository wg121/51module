#include <REGX52.H>
#include "nixie.h"

/* 函数名：Delay
 * 
 * 功能：延时xms毫秒
 * 
 * 参数：xms
 *
 * 备注：
 */
void Delay(unsigned int xms)		//11.0592MHz
{
	unsigned char i, j;

	while(xms--){
		i = 2;
		j = 199;
		do
		{
			while (--j);
		} while (--i);

	}
}

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
		while(1){
				Nixie(1, 1);
				Nixie(2, 2);
				nixie_show(3,3);
				nixie_show(4,4);
		}
}
