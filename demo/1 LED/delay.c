#include "delay.h"

/* ��������delay_ms
 * 
 * ���ܣ���ʱxms����
 * 
 * ������xms
 *
 * ��ע��
 */
void delay_ms(unsigned int xms)		//11.0592MHz
{
	unsigned char i, j;

	while(xms--){
		i = 2;
		j = 199;
		do
		{
			while (--j);
		} while (--i);

	}
}

/* ��������delay_ms
 * 
 * ���ܣ���ʱ10��xus΢��
 * 
 * ������xus
 *
 * ��ע��
 */
void delay_10us_x(unsigned int xus)		//@11.0592MHz
{
	unsigned char i;

	while(xus--){
		i = 25;
		while (--i);
	}	
}
