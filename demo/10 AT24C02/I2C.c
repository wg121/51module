#include "I2C.h"

/* ��������IIC_Start
 *  
 * �������ܣ�IIC��ʼ����λ
 * 
 * ����������void
 * 
 * ��������ֵ��void
 *
 * ��ע��
 */
void IIC_Start(void)
{
	IIC_SDA = 1;
	IIC_SCL = 1;
	IIC_SDA = 0;
	IIC_SCL = 0;
		
}

/* ��������IIC_Stop
 *  
 * �������ܣ�IICֹͣλ
 * 
 * ����������void
 * 
 * ��������ֵ��void
 *
 * ��ע��
 */
void IIC_Stop(void)
{
	IIC_SDA = 0;
	IIC_SCL = 1;
	IIC_SDA = 1;
}

/* ��������IIC_Send_Byte
 *  
 * �������ܣ�IIC����һ���ֽ�
 * 
 * ����������Byte�����͵��ֽ�
 * 
 * ��������ֵ��void
 *
 * ��ע��
 */
void IIC_Send_Byte(unsigned char Byte)
{
	unsigned char i = 0;
	
	for(i = 0; i < 8; ++i){
		IIC_SDA = Byte&(0X80>>i);
		IIC_SCL = 1;
		//delay
		IIC_SCL = 0;
	}
}

/* ��������IIC_Receive_Byte
 *  
 * �������ܣ�IIC�Ӵӻ���ȡ����
 * 
 * ����������void
 * 
 * ��������ֵ���Ӵӻ���ȡ��������
 *
 * ��ע��
 */
unsigned char IIC_Receive_Byte(void)
{
	unsigned char Recv_Byte = 0X00, i = 0;
	IIC_SDA = 1;	//�ͷ�SDA��ʹ���Ϊ����̬���ôӻ�Ϊ�丳ֵ
	
	for(i = 0; i < 8; ++i){
		IIC_SCL = 1;
		if(IIC_SDA) Recv_Byte |= (0X80>>i);
		IIC_SCL = 0;
	}
	
	return Recv_Byte;
}

/* ��������IIC_Ack
 *  
 * �������ܣ�����Ӧ�𣬼��������յ��ӻ����͵����ݺ󣬸��ӻ���Ӧ��
 * 
 * ����������AckBit -- 0��Ӧ��ack����1����Ӧ��nack��
 * 
 * ��������ֵ��void
 *
 * ��ע��
 */
void IIC_Ack(unsigned char AckBit)
{
	IIC_SDA = AckBit;
	IIC_SCL = 1;
	IIC_SCL = 0;
	//IIC_SDA = 1;	//Ӧ��������ͷ�SDA�ߣ��ôӻ�������������
}

/* ��������IIC_Wait_Ack
 *  
 * �������ܣ��ȴ�Ӧ�𣬼�������ӻ�������Ϣ���ӻ���Ӧ��
 * 
 * ����������void
 * 
 * ��������ֵ�����յ���Ӧ��λ��0��Ӧ��ack����1����Ӧ��nack��
 *
 * ��ע��
 */
unsigned char IIC_Wait_Ack(void)
{
	unsigned char Recv_Bit = 0X00;
	IIC_SDA = 1;		//�ͷ�SDA��ʹ���Ϊ����̬���ôӻ�Ϊ�丳ֵ
	
	IIC_SCL = 1;
	if(IIC_SDA) Recv_Bit = 1;	//����д���ǣ�Recv_Byte = IIC_SDA;
	IIC_SCL = 0;
	
	return Recv_Bit;
}