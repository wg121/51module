#include <REGX52.H>

//电机调速

sbit motor = P1^0;
sbit LED = P2^0;

//Count：计数的总数。也就是周期
//Compare：比较的值。就是划分高低电平的值
unsigned char Count = 0, Compare = 0;

void Timer0_Init(void)		//10微秒@11.0592MHz
{
	TMOD &= 0xF0;		//设置定时器模式
	TMOD |= 0x01;		//设置定时器模式
	TL0 = 0xF7;		//设置定时初值
	TH0 = 0xFF;		//设置定时初值
	TF0 = 0;		//清除TF0标志
	TR0 = 1;		//定时器0开始计时
	
	//中断设置
	ET0 = 1;
	EA = 1;
	PT0 = 0;
}


void main(){
	Timer0_Init();
	Compare = 10;
	while(1){
		if(0 == P3^1) {
			Compare = 10;
		}else if(0 == P3^0){
			Compare = 40;
		}else if(0 == P3^2){
			Compare = 70;
		}else if(0 == P3^3){
			Compare = 90;
		}
	}
}

void Timer0_Motor(void) interrupt 1
{
	//设置定时器为 10us 
	TL0 = 0xF7;		//设置定时初值
	TH0 = 0xFF;		//设置定时初值
	
	Count++;
	Count %= 100;
	if(Count < Compare){
		motor = 1;
		LED = 0;
	}else {
		motor = 0;
		LED = 1;
	}
}
