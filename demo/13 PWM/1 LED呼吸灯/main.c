#include <REGX52.H>

sbit LED = P2^0;

//延时函数
void Delay(unsigned int t){
	while(t--);
}

/* 函数功能：模拟的LED呼吸灯的效果 
 */
void Old_LED_Breathe(){
	unsigned char Time, i;
	//LED呼吸灯由暗变亮的过程
	for(Time = 0; Time < 100; ++Time){
		for(i = 0; i < 20; ++i){
		LED = 0;
		Delay(Time);
		LED = 1;
		Delay(100 - Time);
		}
	}
	
	//LED呼吸灯由亮变暗的过程
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
