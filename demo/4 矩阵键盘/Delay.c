#include "Delay.h"

/* 
 * ��������Delay
 *  
 * ���ܣ���ʱXms����
 *
 * ������
 *
 * ��ע��
 */
void Delay(unsigned int Xms){
	unsigned char i, j;

	while(Xms--){
		i = 11;
		j = 190;
		do
		{
			while (--j);
		} while (--i);
	}
}
