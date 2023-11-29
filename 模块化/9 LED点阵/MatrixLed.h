#ifndef __MATRIXLEDD_H__
#define __MATRIXLEDD_H__

#include <REGX52.H>

/* LED������Ļ */

/* 74HC595�����Ŷ��� */
sbit RCK = P3^5;
sbit SCK = P3^6;
sbit SER = P3^4;

#define MATRIX_LED_PORT P0

void _74HC595_init();			//��ʼ������
void matrixled_show(unsigned char column,unsigned char line);


#endif