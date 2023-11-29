#ifndef __DS1302_H__ 
#define __DS1302_H__

#include <REGX52.H>

/* DS1302时钟 */

/* 引脚的定义 */
sbit DS1302_SCLK = P3^6;
sbit DS1302_IO = P3^4;
sbit DS1302_CE = P3^5;

/* 宏定义：注明时间的地址，也就是Command的值 */

#define WRITE_SECOND		0X80		//写秒的地址		
#define READ_SECOND			0X81		//读秒的地址

#define WRITE_MINUTES		0X82		//写分钟的地址
#define READ_MINUTES		0X83		//读分钟的地址

#define WRITE_HOUR			0X84		//写小时的地址
#define READ_HOUR				0X85		//读小时的地址

#define WRITE_DAY				0X86		//写天的地址
#define READ_DAY				0X87		//读天的地址
	
#define WRITE_MONTH			0X88		//写月的地址
#define READ_MONTH			0X89		//读月的地址

#define WRITE_WEAK			0X8A		//写周的地址
#define READ_WEAK				0X8B		//读周的地址

#define WRITE_YEAR			0X8C		//写年的地址
#define READ_YEAR				0X8D		//读年的地址

void DS1302_Init();		//初始化函数
void DS1302_WriteByte(unsigned char Command, unsigned char Data);
unsigned char DS1302_ReadByte(unsigned char Command);

#endif