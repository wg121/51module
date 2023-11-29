#ifndef __ONEWIRE_H__
#define __ONEWIRE_H__

#include <REGX52.H>

/* 单总线使用的引脚 */
sbit OneWire_DQ = P3^7;


/* 单总线协议 */

unsigned char OneWire_Init(void);
//void OneWire_Send_Bit(unsigned char Bit);		//发送一个字节
//unsigned char OneWire_Receive_Bit(void);
void OneWire_Send_Byte(unsigned char Byte);
unsigned char OneWire_Receive_Byte(void);


#endif