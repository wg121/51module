#ifndef __NIXIE_H__
#define __NIXIE_H__
#include <REGX52.H>


/* 0 ~ 9�����ֵ������ֵ */
static unsigned int NUM_[] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};

/* λѡ 3 ��������138����������λѡ */
//#define BIT1_SELE 
//#define BIT2_SELE 
//#define BIT3_SELE

/* ��ѡ */
#define SEG_SELE P0

/* ��̬�������ʾ */
void nixie_show(unsigned char Led, unsigned char Num);

#endif