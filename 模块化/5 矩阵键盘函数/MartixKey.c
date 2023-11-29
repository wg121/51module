#include <REGX52.H>
#include "MartixKey.h"

/* 
 * ��������delay_matrixkey_matrixkey
 *  
 * ���ܣ����������ʱ 20 ���룬Ϊ������
 *
 * ������void
 *
 * ��ע��
 */
static void delay_matrixkey()
{
	unsigned char i, j;
	unsigned char ms = 20;
	
	while(ms--){
		i = 11;
		j = 190;
		do
		{
			while (--j);
		} while (--i);
	}
}

//������̻�ȡ����
/* 
 * ��������matrixKey
 *  
 * ���ܣ�������̻�ȡ����
 *
 * ������void
 *
 * ��ע��
 */
unsigned char	matrixKey()
{
	static unsigned char KeyNum = 0;
		
	P1 = 0xFF;
	P1_3 = 0;
	if(0 == P1_7){delay_matrixkey();while(0 == P1_7);delay_matrixkey();KeyNum=1;}
	if(0 == P1_6){delay_matrixkey();while(0 == P1_6);delay_matrixkey();KeyNum=5;}
	if(0 == P1_5){delay_matrixkey();while(0 == P1_5);delay_matrixkey();KeyNum=9;}
	if(0 == P1_4){delay_matrixkey();while(0 == P1_4);delay_matrixkey();KeyNum=13;}

	P1 = 0xFF;
	P1_2 = 0;
	if(0 == P1_7){delay_matrixkey();while(0 == P1_7);delay_matrixkey();KeyNum=2;}
	if(0 == P1_6){delay_matrixkey();while(0 == P1_6);delay_matrixkey();KeyNum=6;}
	if(0 == P1_5){delay_matrixkey();while(0 == P1_5);delay_matrixkey();KeyNum=10;}
	if(0 == P1_4){delay_matrixkey();while(0 == P1_4);delay_matrixkey();KeyNum=14;}
	
	P1 = 0xFF;
	P1_1 = 0;
	if(0 == P1_7){delay_matrixkey();while(0 == P1_7);delay_matrixkey();KeyNum=3;}
	if(0 == P1_6){delay_matrixkey();while(0 == P1_6);delay_matrixkey();KeyNum=7;}
	if(0 == P1_5){delay_matrixkey();while(0 == P1_5);delay_matrixkey();KeyNum=11;}
	if(0 == P1_4){delay_matrixkey();while(0 == P1_4);delay_matrixkey();KeyNum=15;}
	
	P1 = 0xFF;
	P1_0 = 0;
	if(0 == P1_7){delay_matrixkey();while(0 == P1_7);delay_matrixkey();KeyNum=4;}
	if(0 == P1_6){delay_matrixkey();while(0 == P1_6);delay_matrixkey();KeyNum=8;}
	if(0 == P1_5){delay_matrixkey();while(0 == P1_5);delay_matrixkey();KeyNum=12;}
	if(0 == P1_4){delay_matrixkey();while(0 == P1_4);delay_matrixkey();KeyNum=16;}
	
	return KeyNum;
}
