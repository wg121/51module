#include "nixie.h"

/* 函数名：delay_nixie
 * 
 * 功能：数码管延时 1 毫秒，为了数码管的消影
 * 
 * 参数：void
 *
 * 备注：
 */
static void delay_nixie()		//11.0592MHz
{
	unsigned char i, j;
	
	i = 2;
	j = 199;
	do
	{
		while (--j);
	} while (--i);
}

/* 函数名：nixie_show
 * 
 * 功能：数码管显示函数
 * 
 * 参数：led：哪一个数码管
 *       Num：数码管显示的数字
 *
 * 备注：
 */

void nixie_show(unsigned char Led, unsigned char Num){
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
		SEG_SELE = NUM_[Num];
		delay_nixie();
		SEG_SELE = 0X00;
}