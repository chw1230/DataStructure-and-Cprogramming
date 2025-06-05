#include <stdio.h>

int main(void){
	short s;
	short sum = 0;

	for (s = 1; s >0 ;s++){
		sum += s;
	}

	printf("short sum 0~%d is %d\n",s,sum);
	return 0;
}
