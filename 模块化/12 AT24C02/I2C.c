#include "I2C.h"

/* 函数名：IIC_Start
 *  
 * 函数功能：IIC起始数据位
 * 
 * 函数参数：void
 * 
 * 函数返回值：void
 *
 * 备注：
 */
void IIC_Start(void)
{
	IIC_SDA = 1;
	IIC_SCL = 1;
	IIC_SDA = 0;
	IIC_SCL = 0;
		
}

/* 函数名：IIC_Stop
 *  
 * 函数功能：IIC停止位
 * 
 * 函数参数：void
 * 
 * 函数返回值：void
 *
 * 备注：
 */
void IIC_Stop(void)
{
	IIC_SDA = 0;
	IIC_SCL = 1;
	IIC_SDA = 1;
}

/* 函数名：IIC_Send_Byte
 *  
 * 函数功能：IIC发送一个字节
 * 
 * 函数参数：Byte：发送的字节
 * 
 * 函数返回值：void
 *
 * 备注：
 */
void IIC_Send_Byte(unsigned char Byte)
{
	unsigned char i = 0;
	
	for(i = 0; i < 8; ++i){
		IIC_SDA = Byte&(0X80>>i);
		IIC_SCL = 1;
		//delay
		IIC_SCL = 0;
	}
}

/* 函数名：IIC_Receive_Byte
 *  
 * 函数功能：IIC从从机读取数据
 * 
 * 函数参数：void
 * 
 * 函数返回值：从从机读取到的数据
 *
 * 备注：
 */
unsigned char IIC_Receive_Byte(void)
{
	unsigned char Recv_Byte = 0X00, i = 0;
	IIC_SDA = 1;	//释放SDA，使其变为高阻态，让从机为其赋值
	
	for(i = 0; i < 8; ++i){
		IIC_SCL = 1;
		if(IIC_SDA) Recv_Byte |= (0X80>>i);
		IIC_SCL = 0;
	}
	
	return Recv_Byte;
}

/* 函数名：IIC_Ack
 *  
 * 函数功能：产生应答，即主机接收到从机发送的数据后，给从机的应答
 * 
 * 函数参数：AckBit -- 0：应答（ack）。1：不应答（nack）
 * 
 * 函数返回值：void
 *
 * 备注：
 */
void IIC_Ack(unsigned char AckBit)
{
	IIC_SDA = AckBit;
	IIC_SCL = 1;
	IIC_SCL = 0;
	//IIC_SDA = 1;	//应答结束，释放SDA线，让从机继续发送数据
}

/* 函数名：IIC_Wait_Ack
 *  
 * 函数功能：等待应答，即主机向从机发送消息，从机的应答
 * 
 * 函数参数：void
 * 
 * 函数返回值：接收到的应答位，0：应答（ack）。1：不应答（nack）
 *
 * 备注：
 */
unsigned char IIC_Wait_Ack(void)
{
	unsigned char Recv_Bit = 0X00;
	IIC_SDA = 1;		//释放SDA，使其变为高阻态，让从机为其赋值
	
	IIC_SCL = 1;
	if(IIC_SDA) Recv_Bit = 1;	//或者写法是：Recv_Byte = IIC_SDA;
	IIC_SCL = 0;
	
	return Recv_Bit;
}