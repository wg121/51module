#ifndef __MATRIXLEDD_H__
#define __MATRIXLEDD_H__

#include <REGX52.H>

/* LED点阵屏幕 */

/* 74HC595的引脚定义 */
sbit RCK = P3^5;
sbit SCK = P3^6;
sbit SER = P3^4;

#define MATRIX_LED_PORT P0

void _74HC595_init();			//初始化函数
void matrixled_show(unsigned char column,unsigned char line);


#endif