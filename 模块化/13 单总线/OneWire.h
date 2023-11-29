#ifndef __ONEWIRE_H__
#define __ONEWIRE_H__

#include <REGX52.H>

/* ������ʹ�õ����� */
sbit OneWire_DQ = P3^7;


/* ������Э�� */

unsigned char OneWire_Init(void);
//void OneWire_Send_Bit(unsigned char Bit);		//����һ���ֽ�
//unsigned char OneWire_Receive_Bit(void);
void OneWire_Send_Byte(unsigned char Byte);
unsigned char OneWire_Receive_Byte(void);


#endif