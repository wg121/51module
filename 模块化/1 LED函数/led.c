#include "led.h"

/* ��������led_show
 * 
 * ���ܣ�����8��LED��ĳ����
 * 
 * ������byte
 *
 * ��ע��
 */
void led_show(const unsigned char byte)
{
	LED_PORT = byte;
}