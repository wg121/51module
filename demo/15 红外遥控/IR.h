#ifndef __IR_H__
#define __IR_H__

#include <REGX52.H>

void IR_Init();	//��ʼ������

unsigned char IR_GetDataFlag(void);			//�Ƿ��յ�����
unsigned char IR_GetRepeatFlag(void);		//�Ƿ��յ��ظ�������
unsigned char IR_GetAddress();					//��ȡ��ַ
unsigned char IR_GetCommand();					//��ȡ�����ֵ

#endif
