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
	TR0 = 1;			//定时器控制位
	TMOD &= 0XF0;	//设置定时器0，为16进制计数器
	TMOD |= 0X01;	//
	TL0 = 0X66;		//设置低8位
	TH0 = 0XFC;		//设置高8位
	
	ET0 = 1;			//中断控制位
	EA = 1;				//开启总中断
	PT0 = 0;			//设置优先级
}

//设置定时器1ms，让LED灯翻转
/* 函数名：void timer0_rountion(void) interrupt 1
 * 
 * 功能：定时器0的中断服务函数，每1us产生一个中断，当产生1ms的中断时，反转LED灯的状态
 * 
 * 参数：void
 *
 * 备注：
 */

//void timer0_rountion(void) interrupt 1
//{
//	TL0 = 0X66;		//设置低8位
//	TH0 = 0XFC;		//设置高8位
//	t0_Count++;
//	if(t0_Count >= 1000){   //定时器定时1ms
//		t0_Count = 0;
//		P2_0 = ~P2_0;
//	}
//}