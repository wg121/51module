#include <REGX52.H>
#include "timer.h"

static unsigned int t0_Count = 0;

void Timer0Init(void)		//1����@11.0592MHz
{
	TMOD &= 0xF0;		//���ö�ʱ��ģʽ
	TMOD |= 0X01;	//
	TL0 = 0x66;		//���ö�ʱ��ֵ
	TH0 = 0xFC;		//���ö�ʱ��ֵ
	TF0 = 0;		//���TF0��־
	TR0 = 1;		//��ʱ��0��ʼ��ʱ
	
	ET0 = 1;			//�жϿ���λ
	EA = 1;				//�������ж�
	PT0 = 1;			//�������ȼ�
}


//���ö�ʱ��1us
//void timer0_init(){
//	TF0 = 0;			//��ʱ������жϱ�־λ
//	TR0 = 1;			//��ʱ������λ
//	TMOD &= 0XF0;	//���ö�ʱ��0��Ϊ16���Ƽ�����
//	TMOD |= 0X01;	//
//	TL0 = 0X18;		//���õ�8λ
//	TH0 = 0XFC;		//���ø�8λ
//	
//	ET0 = 1;			//�жϿ���λ
//	EA = 1;				//�������ж�
//	PT0 = 1;			//�������ȼ�
//}

void main(){
	Timer0Init();
	P2_0 = 0;
	while(1){
	
	}
}

//���ö�ʱ��1ms����LED�Ʒ�ת
void timer0_rountion(void) interrupt 1
{
	TL0 = 0X66;		//���õ�8λ
	TH0 = 0XFC;		//���ø�8λ
	t0_Count++;
	if(t0_Count >= 1000){   //��ʱ����ʱ1ms
		t0_Count = 0;
		P2_0 = ~P2_0;
	}
}