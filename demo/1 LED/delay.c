#include "delay.h"

/* 函数名：delay_ms
 * 
 * 功能：延时xms毫秒
 * 
 * 参数：xms
 *
 * 备注：
 */
void delay_ms(unsigned int xms)		//11.0592MHz
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

/* 函数名：delay_ms
 * 
 * 功能：延时10个xus微秒
 * 
 * 参数：xus
 *
 * 备注：
 */
void delay_10us_x(unsigned int xus)		//@11.0592MHz
{
	unsigned char i;

	while(xus--){
		i = 25;
		while (--i);
	}	
}
