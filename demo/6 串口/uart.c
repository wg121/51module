#include "uart.h"

/* ��������uart_init
 * 
 * ���ܣ����ڵĳ�ʼ������
 * 
 * ������void
 *
 * ��ע������λ��8λ�������ʣ���������T1��ʱ�������ã���4800
 */
void uart_init(){		//4800bps@11.0592MHz
	PCON |= 0x80;			//ʹ�ܲ����ʱ���λSMOD
	SCON = 0x50;			//8λ����,�ɱ䲨����
	TMOD &= 0x0F;			//�����ʱ��1ģʽλ
	TMOD |= 0x20;			//�趨��ʱ��1Ϊ8λ�Զ���װ��ʽ
	TL1 = 0xF4;				//�趨��ʱ��ֵ
	TH1 = 0xF4;				//�趨��ʱ����װֵ
	ET1 = 0;					//��ֹ��ʱ��1�ж�
	TR1 = 1;					//������ʱ��1

	ES = 1;		//��ʼ�ж�
	EA = 1;		//��ʼ���ж�
	PS = 1;		//�������ȼ�Ϊ�����ȼ�
}

/* ��������uart_send_byte
 * 
 * ���ܣ�ͨ��51�Ĵ������������ӷ�������
 * 
 * ������byte:���͵��ֽ�
 *
 * ��ע��
 */
void uart_send_byte(unsigned char byte){
	SBUF = byte;
	while(0 == T1);
	T1 = 0;
}

//#if 0

///* ��������void uart_rounter(void) interrupt 4
// * 
//* ���ܣ����ڵĽ����жϷ�����
// * 
//* ������
// *
// * ��ע��
// */
//void uart_rounter(void) interrupt 4
//{
//	if(1 == RI){												//�����ж� -- ���յ�����
//		uart_recv_data = SBUF;
//		uart_send_byte(uart_recv_data++);	//�����յ������ݣ����͸���λ��
//		P2 = ~uart_recv_data;							//����P2��LED�ƣ�λ���͵����ݵ�����
//		RI = 0;														//�����жϣ������λ
//	}
//}
//#endif