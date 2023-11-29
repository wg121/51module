#include "DS1302.h"

/* 函数名称:
 * 
 * 函数功能：初始化时钟线
 *
 * 函数参数：
 * 
 * 函数返回值：
 *
 * 备注：
 */
void DS1302_Init()
{
	DS1302_SCLK = 0;
	DS1302_CE = 0;
}

/* 函数名称:
 * 
 * 函数功能：给DS1302芯片写入具体的数值
 *
 * 函数参数：Command：日期的地址数据
 * 					 Data：日期的具体数据
 *
 * 函数返回值：
 *
 * 备注：
 */
void DS1302_WriteByte(unsigned char Command, unsigned char Data)
{
	unsigned char i = 0;
	//使能，开始写数据
	DS1302_CE = 1;
	
	//写地址，上升沿写入
	for(i = 0; i < 8; ++i)
	{
		DS1302_IO = (Command&(0X01 << i));
		DS1302_SCLK = 1;		//产生一个上升沿
		DS1302_SCLK = 0;
	}
	
	//写数据，上升沿有效
	for(i = 0; i < 8; ++i)
	{
		DS1302_IO = (Data&(0X01 << i));
		DS1302_SCLK = 1;	
		DS1302_SCLK = 0;
	}

	DS1302_CE = 0;	
}

/* 函数名称:
 * 
 * 函数功能：从DS1302芯片的Command所对应的ROM中读取时间的值
 *
 * 函数参数：Command：日期的地址数据
 *
 * 函数返回值：某个日期的具体值
 *
 * 备注：
 */
unsigned char DS1302_ReadByte(unsigned char Command)
{
	unsigned char i = 0, Data = 0X00;
	
	//使能，开始写数据
	DS1302_CE = 1;
	
	//写地址，上升沿写入
	for(i = 0; i < 8; ++i)
	{
		DS1302_IO = (Command&(0X01 << i));
		DS1302_SCLK = 0;
		DS1302_SCLK = 1;
	}

	//2.读数据，下降沿有效
	//写地址，上升沿写入
	for(i = 0; i < 8; ++i)
	{
		DS1302_SCLK = 1;	//产生一个下降沿
		DS1302_SCLK = 0;
		if(DS1302_IO)				//检测到返回数据了，也就是高电平，所以把数据为的该位置1。如果是0，不用置，因为起始8位都是0
			Data |= (0X01 << i);	//将IO口返回的数据读出，先返回最低为，最后返回最高位
	}
	
	DS1302_CE = 0;	//关闭写使能
	DS1302_IO = 0;	//防止下一次，出现写保护，或者是读出数据错误
	
	return Data;
}