#include "DS18B20.h"
#include "LCD1602.h"

/* 函数名称：DS18B20_ConverT
 *
 * 函数功能：DS18B20温度变化函数
 * 
 * 函数参数：void
 * 
 * 函数返回值：void
 *
 * 备注： 
 */
void DS18B20_ConverT(void)
{
	OneWire_Init();
	OneWire_Send_Byte(SKIP_ROM);
	OneWire_Send_Byte(CONVER_T);
}


/* 函数名称：DS18B20_ReadT
 *
 * 函数功能：DS18B20温度读取函数
 * 
 * 函数参数：void
 * 
 * 函数返回值：温度的值，小数点后6位
 *
 * 备注： 
 */
float DS18B20_ReadT(void)
{
	unsigned char TLSB, TMSB;
	int Temp;
	float T;
	
	OneWire_Init();
	OneWire_Send_Byte(SKIP_ROM);
	OneWire_Send_Byte(READ_SCRATCHPAD);
	TLSB = OneWire_Receive_Byte();
	TMSB = OneWire_Receive_Byte();
	Temp = (TMSB << 8) | TLSB;
	T = Temp / 16.0;
	
	return T;
}