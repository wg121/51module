#include "timer.h"

/* ��������timer0_init
 * 
 * ���ܣ���ʱ��0�ĳ�ʼ������ʱ1ms������һ���ж�
 * 
 * ������void
 *
 * ��ע��
 */
void timer0_init()
{
	TF0 = 0;			//��ʱ������жϱ�־λ
	TR0 = 0;			//��ʱ���رռ�ʱ
	TMOD &= 0XF0;	//���ö�ʱ��0��Ϊ16���Ƽ�����
	TMOD |= 0X01;	//
//	TL0 = 0X66;		//���õ�8λ
//	TH0 = 0XFC;		//���ø�8λ
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