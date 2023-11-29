#include "key.h"

/* ��������delay_key
 * 
 * ���ܣ�������ʱ20���룬�������
 * 
 * ������void
 *
 * ��ע��
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

/* ��������key_get
 * 
 * ���ܣ�����ɨ�躯��
 * 
 * ������void
 *
 * ��ע��
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
