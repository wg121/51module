#include <REGX52.H>

sbit LED = P2^0;

//��ʱ����
void Delay(unsigned int t){
	while(t--);
}

/* �������ܣ�ģ���LED�����Ƶ�Ч�� 
 */
void Old_LED_Breathe(){
	unsigned char Time, i;
	//LED�������ɰ������Ĺ���
	for(Time = 0; Time < 100; ++Time){
		for(i = 0; i < 20; ++i){
		LED = 0;
		Delay(Time);
		LED = 1;
		Delay(100 - Time);
		}
	}
	
	//LED�����������䰵�Ĺ���
	for(Time = 100; Time > 0; --Time){
		for(i = 0; i < 20; ++i){
		LED = 0;
		Delay(Time);
		LED = 1;
		Delay(100 - Time);
		}
	}
}

void main(){
	while(1){
		Old_LED_Breathe();
	}	
}
