#include <REGX52.H>
#include "MatrixLed.h"

void main(){
	_74HC595_init();
	while(1){
		//��һ�е�������4��LED��
		matrixled_show(0, 0XFF);
	}
}
