#include "AT24C02.h"

/* ��������AT24C02_Write_Byte
 *  
 * �������ܣ���Address��д������Data
 * 
 * ����������Address��AT24C02��ROM����Ӧ���ڴ��ַ
 *           Data��Ҫ�����ROMд������
 * 
 * ��������ֵ��void
 *
 * ��ע��
 */
void AT24C02_Write_Byte(unsigned char Address, unsigned char Data)
{
	IIC_Start();											//IIC��ʼ
	IIC_Send_Byte(SLAVE_ADDRESS_W);		//д��ַ + д��������ӻ��������ݣ�
	IIC_Wait_Ack();										//�ӻ�Ӧ��
	IIC_Send_Byte(Address);						//дAT24C02��ROM����Ӧ���ڴ��ַ
	IIC_Wait_Ack();										//
	IIC_Send_Byte(Data);							//дAT24C02��ROM����Ӧ���ڴ��ַ������
	IIC_Wait_Ack();										//	
	IIC_Stop();												//IICֹͣ
}

/* ��������AT24C02_Read_Byte
 *  
 * �������ܣ���Address����������Data
 * 
 * ����������Address��AT24C02��ROM����Ӧ���ڴ��ַ
 * 
 * ��������ֵ��AT24C02��ROM����Ӧ���ڴ��ַ����ֵ
 *
 * ��ע��
 */
unsigned char AT24C02_Read_Byte(unsigned char Address)
{
	unsigned char Read_Byte = 0X00;
	
	IIC_Start();											//IIC��ʼ
	IIC_Send_Byte(SLAVE_ADDRESS_W);		//дAT24C02��ַ + д��������ӻ��������ݣ�
	IIC_Wait_Ack();										//�ӻ�Ӧ��
	IIC_Send_Byte(Address);						//дAT24C02��ROM����Ӧ���ڴ��ַ
	IIC_Wait_Ack();										//
	
	IIC_Start();											//
	IIC_Send_Byte(SLAVE_ADDRESS_R);		//дAT24C02��ַ + ����������AT24C02����Ӧ���ڴ��ַ�����ݣ�
	IIC_Wait_Ack();										//	
	Read_Byte = IIC_Receive_Byte();		//��AT24C02����Ӧ���ڴ��ַ������
	IIC_Ack(1);												//����Ӧ��Ϊ���ٽ��մӻ����͵�����
	IIC_Stop();												//IICֹͣ
	
	return Read_Byte;
}