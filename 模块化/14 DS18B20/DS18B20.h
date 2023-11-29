#ifndef __DS18B20_H__
#define __DS18B20_H__

#include "OneWire.h"

#define SKIP_ROM	0XCC				//ROM指令地址  -- 跳过ROM
#define CONVER_T	0X44				//ROM指令地址  -- 开始温度变化
#define READ_SCRATCHPAD	0XBE	//功能指令地址 -- 读暂存器

/* DS18B20温度协议 */

void DS18B20_ConverT(void);
float DS18B20_ReadT(void);

#endif