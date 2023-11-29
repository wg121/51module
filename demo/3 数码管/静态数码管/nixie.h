#ifndef __NIXIE_H__
#define __NIXIE_H__
#include <REGX52.H>


/* 0 ~ 9个数字的数码管值 */
static unsigned int NUM_[] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};

/* 位选 3 个：利用138译码器进行位选 */
//#define BIT1_SELE 
//#define BIT2_SELE 
//#define BIT3_SELE

/* 段选 */
#define SEG_SELE P0

/* 动态数码管显示 */
void nixie_show(unsigned char Led, unsigned char Num);

#endif