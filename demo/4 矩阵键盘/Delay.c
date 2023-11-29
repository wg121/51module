#include "Delay.h"

/* 
 * 函数名：Delay
 *  
 * 功能：延时Xms毫秒
 *
 * 参数：
 *
 * 备注：
 */
void Delay(unsigned int Xms){
	unsigned char i, j;

	while(Xms--){
		i = 11;
		j = 190;
		do
		{
			while (--j);
		} while (--i);
	}
}
