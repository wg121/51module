#ifndef __DS1302_H__ 
#define __DS1302_H__

#include <REGX52.H>

/* DS1302ʱ�� */

/* ���ŵĶ��� */
sbit DS1302_SCLK = P3^6;
sbit DS1302_IO = P3^4;
sbit DS1302_CE = P3^5;

/* �궨�壺ע��ʱ��ĵ�ַ��Ҳ����Command��ֵ */

#define WRITE_SECOND		0X80		//д��ĵ�ַ		
#define READ_SECOND			0X81		//����ĵ�ַ

#define WRITE_MINUTES		0X82		//д���ӵĵ�ַ
#define READ_MINUTES		0X83		//�����ӵĵ�ַ

#define WRITE_HOUR			0X84		//дСʱ�ĵ�ַ
#define READ_HOUR				0X85		//��Сʱ�ĵ�ַ

#define WRITE_DAY				0X86		//д��ĵ�ַ
#define READ_DAY				0X87		//����ĵ�ַ
	
#define WRITE_MONTH			0X88		//д�µĵ�ַ
#define READ_MONTH			0X89		//���µĵ�ַ

#define WRITE_WEAK			0X8A		//д�ܵĵ�ַ
#define READ_WEAK				0X8B		//���ܵĵ�ַ

#define WRITE_YEAR			0X8C		//д��ĵ�ַ
#define READ_YEAR				0X8D		//����ĵ�ַ

void DS1302_Init();		//��ʼ������
void DS1302_WriteByte(unsigned char Command, unsigned char Data);
unsigned char DS1302_ReadByte(unsigned char Command);

#endif