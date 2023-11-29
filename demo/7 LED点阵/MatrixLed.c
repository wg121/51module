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


/* LED������demo */
//74HC595�ĳ�ʼ��������Ҳ����������ʱ���������ڵ͵�ƽ
void _74HC595_init()
{
	RCK = 0;
	SCK = 0;
}

//74HC595дһ�����е�8λ����:Ҳ����ѡ��LED�������һ�У��ߵ�ƽ��Ч
//���磺0x80 -- ��������LED��������ߵ���һ��
static void _74HC594_write_byte(const unsigned char byte)
{
	unsigned char i = 0;
	for(i = 0; i < 8; ++i){		//ѭ���Ľ�8λ����д�뵽оƬ�ڲ�
		SER = (byte&(0X80>>i));
		SCK = 1;
		SCK = 0;
	}
	//��д���8λ���ݣ����������8�����������
	RCK = 1;
	RCK = 0;
}

//LED�����е���LED��
//column���� -- P0��ѡ��:0 ~ 8
//line����   -- ����74HC595ѡ��:0x00 ~ 0xff
void matrixled_show(unsigned char column,unsigned char line)
{
	_74HC594_write_byte(line);
	MATRIX_LED_PORT = ~(0X80>>column);
	delay_ms(1);
	MATRIX_LED_PORT = 0XFF;
}