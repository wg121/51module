#include "timer.h"

/* 函数名：timer0_init
 * 
 * 功能：定时器0的初始化：定时1ms，产生一个中断
 * 
 * 参数：void
 *
 * 备注：
 */
void timer0_init()
{
	TF0 = 0;			//定时器溢出中断标志位
	TR0 = 0;			//定时器关闭计时
	TMOD &= 0XF0;	//设置定时器0，为16进制计数器
	TMOD |= 0X01;	//
//	TL0 = 0X66;		//设置低8位
//	TH0 = 0XFC;		//设置高8位
}

void Timer0_SetCount(unsigned int Value)
{
	TH0 = Value/256;
	TL0 = Value%256;
}

unsigned int Timer0_GetCount(void)
{
	return (TH0<<8)|TL0;
}

void Timer0_Run(unsigned char Flag)
{
	TR0 = Flag;
}