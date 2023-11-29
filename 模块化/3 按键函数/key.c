#include "key.h"

/* 函数名：delay_key
 * 
 * 功能：按键延时20毫秒，软件消抖
 * 
 * 参数：void
 *
 * 备注：
 */
static void delay_key()		//11.0592MHz
{
	unsigned char i, j;
	unsigned char ms = 20;
	while(ms--){
		i = 2;
		j = 199;
		do
		{
			while (--j);
		} while (--i);

	}
}

/* 函数名：key_get
 * 
 * 功能：按键扫描函数
 * 
 * 参数：void
 *
 * 备注：
 */
unsigned char key_get()
{
	unsigned char key_press = 0;
	if(KEY_PRESS == KEY1){
		delay_key();
		while(KEY_PRESS == KEY1);
		key_press = KEY1_RET;
		delay_key();
	}
	else if(KEY_PRESS == KEY2){
		delay_key();	
		while(KEY_PRESS == KEY2);
		key_press = KEY2_RET;
		delay_key();
	}
	else if(KEY_PRESS == KEY3){
		delay_key();
		while(KEY_PRESS == KEY3);
		key_press = KEY3_RET;
		delay_key();
	}
	else if(KEY_PRESS == KEY4){
		delay_key();
		while(KEY_PRESS == KEY4);
		key_press = KEY4_RET;
		delay_key();
	}
	return key_press;
}
