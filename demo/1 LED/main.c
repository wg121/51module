#include <REGX52.H>
#include "delay.h"
#include "led.h"

void main(){
	
	led_show(0xFF);
	
	while(1){
		led_show(0xFE);
		delay_ms(1000);
		led_show(0xFF);
		delay_ms(1000);
	}
}
