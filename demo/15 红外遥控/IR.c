#include "IR.h"
#include "int0.h"
#include "timer.h"

//变量
unsigned int IR_Time;	//定时的时间
unsigned char IR_State;	//状态，利用状态机。0没有信号，1开始信号和重复信号，2数据信号

unsigned char IR_Data[4];	//保存红外传来的数据。0：地址，1地址的取反，2命令，3命令取反
unsigned char IR_pData;		//指向当前数据的位置

//最终输出的变量
unsigned char IR_DataFlag;		//数据是否收到。1数据收到了，0数据没收到
unsigned char	IR_RepeatFlag;	//是否重发
unsigned char IR_Address;			//数据的地址
unsigned char IR_Command;			//命令传回来的数值


void IR_Init()
{
	EXIT_Init();	//外部中断初始化
	timer0_init();	//定时器0初始化
}

unsigned char IR_GetDataFlag(void){
	if(IR_DataFlag) {
		IR_DataFlag = 0;
		return 1;
	}
	return 0;
}

unsigned char IR_GetRepeatFlag(void){
	if(IR_RepeatFlag) {
		IR_RepeatFlag = 0;
		return 1;
	}
	return 0;
}

unsigned char IR_GetAddress(){
	return IR_Address;
}

unsigned char IR_GetCommand(){
	return IR_Command;
}

//外部中断0的中断处理函数
void EXIT0_Routine(void) interrupt 0
{
	if(0 == IR_State){			//传来信号，开始启动
		Timer0_SetCount(0);		//设置计数
		Timer0_Run(1);				//开始计数
		IR_State = 1;					//状态1，开始信号传来
		
	}
	else if(1 == IR_State){	
		IR_Time = Timer0_GetCount();	//获取一次下降沿的时间，开始分析传来的数据的长度
		Timer0_SetCount(0);		//重新设置计数的开始次数

//晶振12M，11.0592M的不对
		if(IR_Time > (13500 - 800) && IR_Time < (13500 + 800)){	//开始信号传来
			IR_State = 2;					//状态2，数据信号即将传来
		}
		else if(IR_Time > (11250 - 500) && IR_Time < (11250 + 500)){	//repeat信号
			IR_RepeatFlag = 1;		//设置重发标志位为1
			Timer0_Run(0);				//结束计数
			IR_State = 0;					//状态0，以一帧为单位
		}
		else{	//信号不对
			IR_State = 1;					//信号不对的话吗，转为本状态
		}
	}
	else if(2 == IR_State){
		
		IR_Time = Timer0_GetCount();	//获取一次下降沿的时间，开始分析传来的数据的长度
		Timer0_SetCount(0);		//重新设置计数的开始次数
		
		if(IR_Time > (1120 - 500) && IR_Time < (1120 + 500)){	//数据“0”信号传来
			IR_Data[IR_pData/8] &= ~(0x01 << (IR_pData%8));
			IR_pData++;
		}
		else if(IR_Time > (2250 - 500) && IR_Time < (2250 + 500)){	//数据“1”信号传来
			IR_Data[IR_pData/8] |= (0x01 << (IR_pData%8));
			IR_pData++;
		}
		else{		//接收到错误的数据信号
			IR_pData = 0;
			IR_State = 1;
		}
		
		if(IR_pData >= 32){	//接受完了数据
			IR_pData = 0;			//指针置0，指向数据的初始位置
			if((IR_Data[0] == ~IR_Data[1]) && (IR_Data[2] == ~IR_Data[3])){	//数据验证，如果正确，就将数据转存
					IR_Address = IR_Data[0];			//地址转存
					IR_Command = IR_Data[2];			//数值转存
					IR_DataFlag = 1;				//接收到数据了
			}
			IR_State = 0;		//回到0状态
			Timer0_Run(0);	//定时器停止
		}
	}
}
