#ifndef __I2C_H__
#define __I2C_H__

#include <REGX52.H>

sbit IIC_SCL = P2^1;
sbit IIC_SDA = P2^0;

void IIC_Start(void);
void IIC_Stop(void);
void IIC_Send_Byte(unsigned char Byte);
unsigned char IIC_Receive_Byte(void);
void IIC_Ack(unsigned char AcckBit);
unsigned char IIC_Wait_Ack(void);

#endif