#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (void){

	int stick;

	int val = 0x01;
	int stickCnt =0;

	scanf("%d", &stick);

	while(1){
		if((stick & val) > 0)
			stickCnt++;

		if(val & 0x80)
			break;

		val = val << 1;
	}

	printf("%d\n", stickCnt);

	system("pause");
}

