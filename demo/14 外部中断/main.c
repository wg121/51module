#include <REGX52.H>

void EXIT_Init(){
	IT0 = 1;
	IE0 = 0;
	EX0 = 1;
	EA = 1;
	PX0 = 1;
}

void main(){
	EXIT_Init();
	while(1){
	
	}
}

void EXIT_Rountion(void) interrupt 0
{
	P2_0 = ~P2_0;
}