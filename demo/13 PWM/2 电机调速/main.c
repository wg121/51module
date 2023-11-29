#include <REGX52.H>

//�������

sbit motor = P1^0;
sbit LED = P2^0;

//Count��������������Ҳ��������
//Compare���Ƚϵ�ֵ�����ǻ��ָߵ͵�ƽ��ֵ
unsigned char Count = 0, Compare = 0;

void Timer0_Init(void)		//10΢��@11.0592MHz
{
	TMOD &= 0xF0;		//���ö�ʱ��ģʽ
	TMOD |= 0x01;		//���ö�ʱ��ģʽ
	TL0 = 0xF7;		//���ö�ʱ��ֵ
	TH0 = 0xFF;		//���ö�ʱ��ֵ
	TF0 = 0;		//���TF0��־
	TR0 = 1;		//��ʱ��0��ʼ��ʱ
	
	//�ж�����
	ET0 = 1;
	EA = 1;
	PT0 = 0;
}


void main(){
	Timer0_Init();
	Compare = 10;
	while(1){
		if(0 == P3^1) {
			Compare = 10;
		}else if(0 == P3^0){
			Compare = 40;
		}else if(0 == P3^2){
			Compare = 70;
		}else if(0 == P3^3){
			Compare = 90;
		}
	}
}

void Timer0_Motor(void) interrupt 1
{
	//���ö�ʱ��Ϊ 10us 
	TL0 = 0xF7;		//���ö�ʱ��ֵ
	TH0 = 0xFF;		//���ö�ʱ��ֵ
	
	Count++;
	Count %= 100;
	if(Count < Compare){
		motor = 1;
		LED = 0;
	}else {
		motor = 0;
		LED = 1;
	}
}
