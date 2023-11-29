#include "MatrixLed.h"

static void delay_ms(unsigned char xms)		//@11.0592MHz
{
	unsigned char i, j;

	while(xms--){
		i = 2;
		j = 199;
		do
		{
			while (--j);
		} while (--i);
	}	
}


/* LED点阵屏demo */
//74HC595的初始化函数：也就是让两个时钟引脚置于低电平
void _74HC595_init()
{
	RCK = 0;
	SCK = 0;
}

//74HC595写一个串行的8位数据:也就是选择LED点阵的哪一行，高电平有效
//例如：0x80 -- 就是启动LED点阵的最后高的哪一行
static void _74HC594_write_byte(const unsigned char byte)
{
	unsigned char i = 0;
	for(i = 0; i < 8; ++i){		//循环的将8位数据写入到芯片内部
		SER = (byte&(0X80>>i));
		SCK = 1;
		SCK = 0;
	}
	//将写入的8位数据，并行输出到8个并行输出口
	RCK = 1;
	RCK = 0;
}

//LED点阵按列点亮LED灯
//column：列 -- P0口选择:0 ~ 8
//line：行   -- 利用74HC595选择:0x00 ~ 0xff
void matrixled_show(unsigned char column,unsigned char line)
{
	_74HC594_write_byte(line);
	MATRIX_LED_PORT = ~(0X80>>column);
	delay_ms(1);
	MATRIX_LED_PORT = 0XFF;
}