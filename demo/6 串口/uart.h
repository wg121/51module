#ifndef __UART_H__
#define __UART_H__

#include <REGX52.H>

/* 串口的初始化头文件 */

//51的串口初始化 -- 波特率设置，在T1定时器里面
void uart_init();

//通过51的uart发送字节
void uart_send_byte(unsigned char byte);


#endif