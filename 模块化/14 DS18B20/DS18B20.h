#ifndef __DS18B20_H__
#define __DS18B20_H__

#include "OneWire.h"

#define SKIP_ROM	0XCC				//ROMָ���ַ  -- ����ROM
#define CONVER_T	0X44				//ROMָ���ַ  -- ��ʼ�¶ȱ仯
#define READ_SCRATCHPAD	0XBE	//����ָ���ַ -- ���ݴ���

/* DS18B20�¶�Э�� */

void DS18B20_ConverT(void);
float DS18B20_ReadT(void);

#endif