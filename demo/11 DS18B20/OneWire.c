#include "OneWire.h"

/* 函数名称：OneWire_Init
 *
 * 函数功能：单总线协议的初始化（主机拉低电平，释放总线，看从机是否拉低总线）
 * 
 * 函数参数：void
 * 
 * 函数返回值：从机是否存在（是否产生应答）。0：从机已响应，1：从机未响应
 *
 * 备注： 
 */
unsigned char OneWire_Init(void)
{
	unsigned char AckBit = 1;
	unsigned char i;
	
	OneWire_DQ = 1;
	OneWire_DQ = 0;
	i = 230; while (--i);		//主机拉低电平 500us
	OneWire_DQ = 1;					//主机释放总线，让从机拉低主线
	i = 32; while (--i);		//主机拉低电平 70us
	AckBit = OneWire_DQ;		//读取从机是否存在（从机存在的话，会拉低电平，也就是输出0）
	i = 230; while (--i);		//主机拉低电平 500us
	
	return AckBit;
}

/* 函数名称：OneWire_Send_Bit
 *
 * 函数功能：单总线协议发送一个字节
 * 
 * 函数参数：Bit：发送的字节，1或0
 * 
 * 函数返回值：void
 *
 * 备注： 
 */
static void OneWire_Send_Bit(unsigned char Bit)
{
	unsigned char i = 0;
	
	OneWire_DQ = 0;
	i = 4; while (--i);			//主机拉低电平 10us
	OneWire_DQ = Bit;				//此时就可以省去判断Bit的值的时间
	i = 22; while (--i);		//主机拉低电平 50us
	OneWire_DQ = 1;					//释放总线
}

/* 函数名称：
 *
 * 函数功能：单总线协议接收一个字节
 * 
 * 函数参数：void
 * 
 * 函数返回值：从机发送给主机的电平值
 *
 * 备注： 
 */
static unsigned char OneWire_Receive_Bit(void)
{
	unsigned char AckBit = 0;
	unsigned char i = 0;
	
	OneWire_DQ = 0;
	i = 2;	while (--i);				//延时5us
	OneWire_DQ = 1;							//释放总线，然后读取从机发送的字节
	i = 2;	while (--i);				//延时5us
	AckBit = OneWire_DQ;				//读取从机发送的信号
	i = 22; while (--i);				//主机拉低电平 50us
	
	return AckBit;							//返回从机发送给主机的电平值
}

/* 函数名称：OneWire_Send_Byte
 *
 * 函数功能：单总线协议发送一位数据（8个字节）
 * 
 * 函数参数：Byte：主机发送的字节
 * 
 * 函数返回值：void
 *
 * 备注： 
 */
void OneWire_Send_Byte(unsigned char Byte)
{
	unsigned char i = 0;
	
	for(i = 0; i < 8; ++i){
		OneWire_Send_Bit(Byte&(0x01 << i));
	}
}

/* 函数名称：OneWire_Receive_Byte
 *
 * 函数功能：单总线协议接收一位（8个字节）
 * 
 * 函数参数：void
 * 
 * 函数返回值：从机发送给主机的字节
 *
 * 备注： 
 */
unsigned char OneWire_Receive_Byte(void)
{
	unsigned char AckByte = 0x00;
	unsigned char i = 0;
	
	for(i = 0; i < 8; ++i){
		if(OneWire_Receive_Bit())
				AckByte |= (0X01 << i);
	}
	
	return AckByte;
}