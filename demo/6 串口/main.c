#include <REGX52.H>
//#include <stdlib.h>
#include "uart.h"

//全局变量
unsigned char uart_send_data = 0x00;		//发送数据的变量
unsigned char uart_recv_data = 0x00;		//接收数据的变量

////////////////////////////////////////////////
/*       下面的都是随便写的      */
//接收缓存区的大小
//const unsigned char RECV_LEN = 16;

////接收缓存区指针
//unsigned char *uart_recv_buf = NULL;

////接收缓存区的申请
//unsigned char *recv_buf_init(const unsigned char len)
//{
//	if(len < 0 || len > 128){		//缓存区太大，超过了51的内存区域
//		return NULL;
//	}
//	
//	uart_recv_buf = (unsigned char *)malloc(sizeof(unsigned char) * len);
//	
//	//申请内存失败
//	if(NULL == uart_recv_buf) {
//		return NULL;
//	}
//	
//	//返回申请成功的内存的起始地址的指针
//	return uart_recv_buf;
//}
//////////////////////////////////////////////////////

//延时xms毫秒
void delay_xms(unsigned int xms)		//@11.0592MHz
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


//51的串口初始化 -- 波特率设置，在T1定时器里面
//void uart_init_(){		//4800bps@11.0592MHz
//	PCON |= 0x80;			//使能波特率倍速位SMOD
//	SCON = 0x50;			//8位数据,可变波特率
//	TMOD &= 0x0F;			//清除定时器1模式位
//	TMOD |= 0x20;			//设定定时器1为8位自动重装方式
//	TL1 = 0xD0;				//设定定时初值
//	TH1 = 0xFF;				//设定定时器重装值
//	ET1 = 0;					//禁止定时器1中断
//	TR1 = 1;					//启动定时器1

////中断 -- 使能
//	ES = 1;		//开始中断
//	EA = 1;		//开始总中断
//	PS = 1;		//设置优先级为高优先级
//}

//通过51的uart发送字节
//void uart_send_byte_(const unsigned char byte){
//	SBUF = byte;
//	while(0 == T1);
//	T1 = 0;
//}

/* 主函数 */
void main(){
	uart_init();
	while(1){
		/* 每隔1秒，发送一个unsigned char 的数据 */
		//delay_xms(500);
		uart_send_byte(uart_send_data++);
	}
}

void uart_rounter(void) interrupt 4
{
	if(1 == RI){		//接收中断 -- 接收到数据
		uart_recv_data = SBUF;
		uart_send_byte(uart_recv_data);	//将接收到的数据，发送给上位机
		P2 = ~uart_recv_data;							//设置P2的LED灯，位发送的数据的样子
		RI = 0;				//接收中断，软件复位
	}
}
