#include "led.h"

/* 函数名：led_show
 * 
 * 功能：点亮8个LED的某几个
 * 
 * 参数：byte
 *
 * 备注：
 */
void led_show(const unsigned char byte)
{
	LED_PORT = byte;
}