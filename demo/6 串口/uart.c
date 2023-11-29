#include "uart.h"

/* 函数名：uart_init
 * 
 * 功能：串口的初始化函数
 * 
 * 参数：void
 *
 * 备注：数据位：8位。波特率（波特率在T1定时器里设置）：4800
 */
void uart_init(){		//4800bps@11.0592MHz
	PCON |= 0x80;			//使能波特率倍速位SMOD
	SCON = 0x50;			//8位数据,可变波特率
	TMOD &= 0x0F;			//清除定时器1模式位
	TMOD |= 0x20;			//设定定时器1为8位自动重装方式
	TL1 = 0xF4;				//设定定时初值
	TH1 = 0xF4;				//设定定时器重装值
	ET1 = 0;					//禁止定时器1中断
	TR1 = 1;					//启动定时器1

	ES = 1;		//开始中断
	EA = 1;		//开始总中断
	PS = 1;		//设置优先级为高优先级
}

/* 函数名：uart_send_byte
 * 
 * 功能：通过51的串口向其他机子发送数据
 * 
 * 参数：byte:发送的字节
 *
 * 备注：
 */
void uart_send_byte(unsigned char byte){
	SBUF = byte;
	while(0 == T1);
	T1 = 0;
}

//#if 0

///* 函数名：void uart_rounter(void) interrupt 4
// * 
//* 功能：串口的接收中断服务函数
// * 
//* 参数：
// *
// * 备注：
// */
//void uart_rounter(void) interrupt 4
//{
//	if(1 == RI){												//接收中断 -- 接收到数据
//		uart_recv_data = SBUF;
//		uart_send_byte(uart_recv_data++);	//将接收到的数据，发送给上位机
//		P2 = ~uart_recv_data;							//设置P2的LED灯，位发送的数据的样子
//		RI = 0;														//接收中断，软件复位
//	}
//}
//#endif