#ifndef __UART_H__
#define __UART_H__

#include <REGX52.H>

/* ���ڵĳ�ʼ��ͷ�ļ� */

//51�Ĵ��ڳ�ʼ�� -- ���������ã���T1��ʱ������
void uart_init();

//ͨ��51��uart�����ֽ�
void uart_send_byte(unsigned char byte);


#endif