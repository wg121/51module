#include "OneWire.h"

/* �������ƣ�OneWire_Init
 *
 * �������ܣ�������Э��ĳ�ʼ�����������͵�ƽ���ͷ����ߣ����ӻ��Ƿ��������ߣ�
 * 
 * ����������void
 * 
 * ��������ֵ���ӻ��Ƿ���ڣ��Ƿ����Ӧ�𣩡�0���ӻ�����Ӧ��1���ӻ�δ��Ӧ
 *
 * ��ע�� 
 */
unsigned char OneWire_Init(void)
{
	unsigned char AckBit = 1;
	unsigned char i;
	
	OneWire_DQ = 1;
	OneWire_DQ = 0;
	i = 230; while (--i);		//�������͵�ƽ 500us
	OneWire_DQ = 1;					//�����ͷ����ߣ��ôӻ���������
	i = 32; while (--i);		//�������͵�ƽ 70us
	AckBit = OneWire_DQ;		//��ȡ�ӻ��Ƿ���ڣ��ӻ����ڵĻ��������͵�ƽ��Ҳ�������0��
	i = 230; while (--i);		//�������͵�ƽ 500us
	
	return AckBit;
}

/* �������ƣ�OneWire_Send_Bit
 *
 * �������ܣ�������Э�鷢��һ���ֽ�
 * 
 * ����������Bit�����͵��ֽڣ�1��0
 * 
 * ��������ֵ��void
 *
 * ��ע�� 
 */
static void OneWire_Send_Bit(unsigned char Bit)
{
	unsigned char i = 0;
	
	OneWire_DQ = 0;
	i = 4; while (--i);			//�������͵�ƽ 10us
	OneWire_DQ = Bit;				//��ʱ�Ϳ���ʡȥ�ж�Bit��ֵ��ʱ��
	i = 22; while (--i);		//�������͵�ƽ 50us
	OneWire_DQ = 1;					//�ͷ�����
}

/* �������ƣ�
 *
 * �������ܣ�������Э�����һ���ֽ�
 * 
 * ����������void
 * 
 * ��������ֵ���ӻ����͸������ĵ�ƽֵ
 *
 * ��ע�� 
 */
static unsigned char OneWire_Receive_Bit(void)
{
	unsigned char AckBit = 0;
	unsigned char i = 0;
	
	OneWire_DQ = 0;
	i = 2;	while (--i);				//��ʱ5us
	OneWire_DQ = 1;							//�ͷ����ߣ�Ȼ���ȡ�ӻ����͵��ֽ�
	i = 2;	while (--i);				//��ʱ5us
	AckBit = OneWire_DQ;				//��ȡ�ӻ����͵��ź�
	i = 22; while (--i);				//�������͵�ƽ 50us
	
	return AckBit;							//���شӻ����͸������ĵ�ƽֵ
}

/* �������ƣ�OneWire_Send_Byte
 *
 * �������ܣ�������Э�鷢��һλ���ݣ�8���ֽڣ�
 * 
 * ����������Byte���������͵��ֽ�
 * 
 * ��������ֵ��void
 *
 * ��ע�� 
 */
void OneWire_Send_Byte(unsigned char Byte)
{
	unsigned char i = 0;
	
	for(i = 0; i < 8; ++i){
		OneWire_Send_Bit(Byte&(0x01 << i));
	}
}

/* �������ƣ�OneWire_Receive_Byte
 *
 * �������ܣ�������Э�����һλ��8���ֽڣ�
 * 
 * ����������void
 * 
 * ��������ֵ���ӻ����͸��������ֽ�
 *
 * ��ע�� 
 */
unsigned char OneWire_Receive_Byte(void)
{
	unsigned char AckByte = 0x00;
	unsigned char i = 0;
	
	for(i = 0; i < 8; ++i){
		if(OneWire_Receive_Bit())
				AckByte |= (0X01 << i);
	}
	
	return AckByte;
}