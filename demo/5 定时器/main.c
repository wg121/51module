#include <REGX52.H>
#include "timer.h"

static unsigned int t0_Count = 0;

void Timer0Init(void)		//1毫秒@11.0592MHz
{
	TMOD &= 0xF0;		//设置定时器模式
	TMOD |= 0X01;	//
	TL0 = 0x66;		//设置定时初值
	TH0 = 0xFC;		//设置定时初值
	TF0 = 0;		//清除TF0标志
	TR0 = 1;		//定时器0开始计时
	
	ET0 = 1;			//中断控制位
	EA = 1;				//开启总中断
	PT0 = 1;			//设置优先级
}


//设置定时器1us
//void timer0_init(){
//	TF0 = 0;			//定时器溢出中断标志位
//	TR0 = 1;			//定时器控制位
//	TMOD &= 0XF0;	//设置定时器0，为16进制计数器
//	TMOD |= 0X01;	//
//	TL0 = 0X18;		//设置低8位
//	TH0 = 0XFC;		//设置高8位
//	
//	ET0 = 1;			//中断控制位
//	EA = 1;				//开启总中断
//	PT0 = 1;			//设置优先级
//}

void main(){
	Timer0Init();
	P2_0 = 0;
	while(1){
	
	}
}

//设置定时器1ms，让LED灯翻转
void timer0_rountion(void) interrupt 1
{
	TL0 = 0X66;		//设置低8位
	TH0 = 0XFC;		//设置高8位
	t0_Count++;
	if(t0_Count >= 1000){   //定时器定时1ms
		t0_Count = 0;
		P2_0 = ~P2_0;
	}
}