#include "DS18B20.h"
#include "LCD1602.h"

/* �������ƣ�DS18B20_ConverT
 *
 * �������ܣ�DS18B20�¶ȱ仯����
 * 
 * ����������void
 * 
 * ��������ֵ��void
 *
 * ��ע�� 
 */
void DS18B20_ConverT(void)
{
	OneWire_Init();
	OneWire_Send_Byte(SKIP_ROM);
	OneWire_Send_Byte(CONVER_T);
}


/* �������ƣ�DS18B20_ReadT
 *
 * �������ܣ�DS18B20�¶ȶ�ȡ����
 * 
 * ����������void
 * 
 * ��������ֵ���¶ȵ�ֵ��С�����6λ
 *
 * ��ע�� 
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