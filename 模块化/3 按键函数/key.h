#ifndef __KEY_H__
#define __KEY_H__

#include <REGX52.H>

/* ��������Ӧ������ */
#define KEY1 P3_1 
#define KEY2 P3_0
#define KEY3 P3_2
#define KEY4 P3_3

/* ���ص�KEY��ֵ */
#define KEY1_RET 1
#define KEY2_RET 2
#define KEY3_RET 3
#define KEY4_RET 4

/* �������µ��ж� */
#define KEY_PRESS 0

//�������غ���
unsigned char key_get();

#endif