#ifndef __IR_H__
#define __IR_H__

#include <REGX52.H>

void IR_Init();	//初始化函数

unsigned char IR_GetDataFlag(void);			//是否收到数据
unsigned char IR_GetRepeatFlag(void);		//是否收到重复的数据
unsigned char IR_GetAddress();					//获取地址
unsigned char IR_GetCommand();					//获取命令的值

#endif
