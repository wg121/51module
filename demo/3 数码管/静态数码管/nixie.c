#include "nixie.h"

/* ��������delay_nixie
 * 
 * ���ܣ��������ʱ 1 ���룬Ϊ������ܵ���Ӱ
 * 
 * ������void
 *
 * ��ע��
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

/* ��������nixie_show
 * 
 * ���ܣ��������ʾ����
 * 
 * ������led����һ�������
 *       Num���������ʾ������
 *
 * ��ע��
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