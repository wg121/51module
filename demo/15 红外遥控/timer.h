#ifndef __TIMER_H__
#define __TIMER_H__

#include <REGX52.H>

/* 定时器0初始化函数 */
void timer0_init();

void Timer0_SetCount(unsigned int Value);
unsigned int Timer0_GetCount(void);
void Timer0_Run(unsigned char Flag);

#endif