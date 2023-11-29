#ifndef __AT24C02_H__
#define __AT24C02_H__

#include <REGX52.H>
#include "I2C.h"

#define SLAVE_ADDRESS_W 0xA0
#define SLAVE_ADDRESS_R 0xA1

void AT24C02_Write_Byte(unsigned char Address, unsigned char Data);
unsigned char AT24C02_Read_Byte(unsigned char Address);

#endif
