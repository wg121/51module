#ifndef __KEY_H__
#define __KEY_H__

#include <REGX52.H>

/* 按键所对应的引脚 */
#define KEY1 P3_1 
#define KEY2 P3_0
#define KEY3 P3_2
#define KEY4 P3_3

/* 返回的KEY的值 */
#define KEY1_RET 1
#define KEY2_RET 2
#define KEY3_RET 3
#define KEY4_RET 4

/* 按键按下的判断 */
#define KEY_PRESS 0

//按键返回函数
unsigned char key_get();

#endif