#ifndef __LCD1602_H__
#define __LCD1602_H__

#include <REGX52.H>

/* LCD1602的引脚复用定义 */
sbit LCD_RS = P2^6;
sbit LCD_RW = P2^5;
sbit LCD_E  = P2^7;

/* D0 ~ D7 */
#define LCD_DATA_PORT P0

void LCD_Init(void);
void LCD_ShowChar(unsigned char Line, unsigned char Column, unsigned char Char);


#endif