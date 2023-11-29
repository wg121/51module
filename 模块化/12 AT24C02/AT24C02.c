#include "AT24C02.h"

/* 函数名：AT24C02_Write_Byte
 *  
 * 函数功能：在Address处写入数据Data
 * 
 * 函数参数：Address：AT24C02中ROM所对应的内存地址
 *           Data：要给这块ROM写的数据
 * 
 * 函数返回值：void
 *
 * 备注：
 */
void AT24C02_Write_Byte(unsigned char Address, unsigned char Data)
{
	IIC_Start();											//IIC开始
	IIC_Send_Byte(SLAVE_ADDRESS_W);		//写地址 + 写操作（向从机发送数据）
	IIC_Wait_Ack();										//从机应答
	IIC_Send_Byte(Address);						//写AT24C02中ROM所对应的内存地址
	IIC_Wait_Ack();										//
	IIC_Send_Byte(Data);							//写AT24C02中ROM所对应的内存地址的数据
	IIC_Wait_Ack();										//	
	IIC_Stop();												//IIC停止
}

/* 函数名：AT24C02_Read_Byte
 *  
 * 函数功能：从Address处读出数据Data
 * 
 * 函数参数：Address：AT24C02中ROM所对应的内存地址
 * 
 * 函数返回值：AT24C02中ROM所对应的内存地址的数值
 *
 * 备注：
 */
unsigned char AT24C02_Read_Byte(unsigned char Address)
{
	unsigned char Read_Byte = 0X00;
	
	IIC_Start();											//IIC开始
	IIC_Send_Byte(SLAVE_ADDRESS_W);		//写AT24C02地址 + 写操作（向从机发送数据）
	IIC_Wait_Ack();										//从机应答
	IIC_Send_Byte(Address);						//写AT24C02中ROM所对应的内存地址
	IIC_Wait_Ack();										//
	
	IIC_Start();											//
	IIC_Send_Byte(SLAVE_ADDRESS_R);		//写AT24C02地址 + 读操作（从AT24C02所对应的内存地址读数据）
	IIC_Wait_Ack();										//	
	Read_Byte = IIC_Receive_Byte();		//从AT24C02所对应的内存地址读数据
	IIC_Ack(1);												//主机应答，为不再接收从机发送的数据
	IIC_Stop();												//IIC停止
	
	return Read_Byte;
}