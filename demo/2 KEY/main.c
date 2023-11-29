#include <REGX52.H>
#include "key.h"


void main(){
	unsigned char Key_Num = 0;
	while(1){
		Key_Num = key_get();
		if(Key_Num){
			if(KEY1_RET == Key_Num) P2_0 = ~P2_0;
			//...
		}
	}
}
