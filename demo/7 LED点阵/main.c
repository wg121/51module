#include <REGX52.H>
#include "MatrixLed.h"

void main(){
	_74HC595_init();
	while(1){
		//第一列的最上面4个LED亮
		matrixled_show(0, 0XFF);
	}
}
