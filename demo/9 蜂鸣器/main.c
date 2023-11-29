#include <REGX52.H>

sbit BEEP = P1^5;

void Delay1ms()		//@11.0592MHz
{
	unsigned char i, j;

	i = 2;
	j = 199;
	do
	{
		while (--j);
	} while (--i);
}



void beep(){
	unsigned int count = 0;
	
	for(count = 0; count < 500; ++count){
		BEEP = !BEEP;
		Delay1ms();
	}
}

void main(){
	beep();
	while(1){
	
	}
}