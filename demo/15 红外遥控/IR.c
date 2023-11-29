#include "IR.h"
#include "int0.h"
#include "timer.h"

//����
unsigned int IR_Time;	//��ʱ��ʱ��
unsigned char IR_State;	//״̬������״̬����0û���źţ�1��ʼ�źź��ظ��źţ�2�����ź�

unsigned char IR_Data[4];	//������⴫�������ݡ�0����ַ��1��ַ��ȡ����2���3����ȡ��
unsigned char IR_pData;		//ָ��ǰ���ݵ�λ��

//��������ı���
unsigned char IR_DataFlag;		//�����Ƿ��յ���1�����յ��ˣ�0����û�յ�
unsigned char	IR_RepeatFlag;	//�Ƿ��ط�
unsigned char IR_Address;			//���ݵĵ�ַ
unsigned char IR_Command;			//�����������ֵ


void IR_Init()
{
	EXIT_Init();	//�ⲿ�жϳ�ʼ��
	timer0_init();	//��ʱ��0��ʼ��
}

unsigned char IR_GetDataFlag(void){
	if(IR_DataFlag) {
		IR_DataFlag = 0;
		return 1;
	}
	return 0;
}

unsigned char IR_GetRepeatFlag(void){
	if(IR_RepeatFlag) {
		IR_RepeatFlag = 0;
		return 1;
	}
	return 0;
}

unsigned char IR_GetAddress(){
	return IR_Address;
}

unsigned char IR_GetCommand(){
	return IR_Command;
}

//�ⲿ�ж�0���жϴ�����
void EXIT0_Routine(void) interrupt 0
{
	if(0 == IR_State){			//�����źţ���ʼ����
		Timer0_SetCount(0);		//���ü���
		Timer0_Run(1);				//��ʼ����
		IR_State = 1;					//״̬1����ʼ�źŴ���
		
	}
	else if(1 == IR_State){	
		IR_Time = Timer0_GetCount();	//��ȡһ���½��ص�ʱ�䣬��ʼ�������������ݵĳ���
		Timer0_SetCount(0);		//�������ü����Ŀ�ʼ����

//����12M��11.0592M�Ĳ���
		if(IR_Time > (13500 - 800) && IR_Time < (13500 + 800)){	//��ʼ�źŴ���
			IR_State = 2;					//״̬2�������źż�������
		}
		else if(IR_Time > (11250 - 500) && IR_Time < (11250 + 500)){	//repeat�ź�
			IR_RepeatFlag = 1;		//�����ط���־λΪ1
			Timer0_Run(0);				//��������
			IR_State = 0;					//״̬0����һ֡Ϊ��λ
		}
		else{	//�źŲ���
			IR_State = 1;					//�źŲ��ԵĻ���תΪ��״̬
		}
	}
	else if(2 == IR_State){
		
		IR_Time = Timer0_GetCount();	//��ȡһ���½��ص�ʱ�䣬��ʼ�������������ݵĳ���
		Timer0_SetCount(0);		//�������ü����Ŀ�ʼ����
		
		if(IR_Time > (1120 - 500) && IR_Time < (1120 + 500)){	//���ݡ�0���źŴ���
			IR_Data[IR_pData/8] &= ~(0x01 << (IR_pData%8));
			IR_pData++;
		}
		else if(IR_Time > (2250 - 500) && IR_Time < (2250 + 500)){	//���ݡ�1���źŴ���
			IR_Data[IR_pData/8] |= (0x01 << (IR_pData%8));
			IR_pData++;
		}
		else{		//���յ�����������ź�
			IR_pData = 0;
			IR_State = 1;
		}
		
		if(IR_pData >= 32){	//������������
			IR_pData = 0;			//ָ����0��ָ�����ݵĳ�ʼλ��
			if((IR_Data[0] == ~IR_Data[1]) && (IR_Data[2] == ~IR_Data[3])){	//������֤�������ȷ���ͽ�����ת��
					IR_Address = IR_Data[0];			//��ַת��
					IR_Command = IR_Data[2];			//��ֵת��
					IR_DataFlag = 1;				//���յ�������
			}
			IR_State = 0;		//�ص�0״̬
			Timer0_Run(0);	//��ʱ��ֹͣ
		}
	}
}
