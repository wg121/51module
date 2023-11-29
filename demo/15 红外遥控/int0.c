#include "int0.h"

//外部中断
void EXIT_Init(){
	IT0 = 1;	//下降沿触发
	IE0 = 0;	//中断标志位
	EX0 = 1;	//中断开始
	EA = 1;		//开启总中断
	PX0 = 1;	//设置高优先级
}