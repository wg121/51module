#include <REGX52.H>
//#include <stdlib.h>
#include "uart.h"

//ȫ�ֱ���
unsigned char uart_send_data = 0x00;		//�������ݵı���
unsigned char uart_recv_data = 0x00;		//�������ݵı���

////////////////////////////////////////////////
/*       ����Ķ������д��      */
//���ջ������Ĵ�С
//const unsigned char RECV_LEN = 16;

////���ջ�����ָ��
//unsigned char *uart_recv_buf = NULL;

////���ջ�����������
//unsigned char *recv_buf_init(const unsigned char len)
//{
//	if(len < 0 || len > 128){		//������̫�󣬳�����51���ڴ�����
//		return NULL;
//	}
//	
//	uart_recv_buf = (unsigned char *)malloc(sizeof(unsigned char) * len);
//	
//	//�����ڴ�ʧ��
//	if(NULL == uart_recv_buf) {
//		return NULL;
//	}
//	
//	//��������ɹ����ڴ����ʼ��ַ��ָ��
//	return uart_recv_buf;
//}
//////////////////////////////////////////////////////

//��ʱxms����
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


//51�Ĵ��ڳ�ʼ�� -- ���������ã���T1��ʱ������
//void uart_init_(){		//4800bps@11.0592MHz
//	PCON |= 0x80;			//ʹ�ܲ����ʱ���λSMOD
//	SCON = 0x50;			//8λ����,�ɱ䲨����
//	TMOD &= 0x0F;			//�����ʱ��1ģʽλ
//	TMOD |= 0x20;			//�趨��ʱ��1Ϊ8λ�Զ���װ��ʽ
//	TL1 = 0xD0;				//�趨��ʱ��ֵ
//	TH1 = 0xFF;				//�趨��ʱ����װֵ
//	ET1 = 0;					//��ֹ��ʱ��1�ж�
//	TR1 = 1;					//������ʱ��1

////�ж� -- ʹ��
//	ES = 1;		//��ʼ�ж�
//	EA = 1;		//��ʼ���ж�
//	PS = 1;		//�������ȼ�Ϊ�����ȼ�
//}

//ͨ��51��uart�����ֽ�
//void uart_send_byte_(const unsigned char byte){
//	SBUF = byte;
//	while(0 == T1);
//	T1 = 0;
//}

/* ������ */
void main(){
	uart_init();
	while(1){
		/* ÿ��1�룬����һ��unsigned char ������ */
		//delay_xms(500);
		uart_send_byte(uart_send_data++);
	}
}

void uart_rounter(void) interrupt 4
{
	if(1 == RI){		//�����ж� -- ���յ�����
		uart_recv_data = SBUF;
		uart_send_byte(uart_recv_data);	//�����յ������ݣ����͸���λ��
		P2 = ~uart_recv_data;							//����P2��LED�ƣ�λ���͵����ݵ�����
		RI = 0;				//�����жϣ������λ
	}
}
