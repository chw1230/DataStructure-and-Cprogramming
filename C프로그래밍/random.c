#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void){
	int r; 
	srand((unsigned int) time(NULL)); // 현재 시간을 시드로 사용

	for ( int i = 0;i<10;i++){ 
		printf("%d번 random int = %d\n",i+1, rand()%10); // %10으로 0~9 범위의 랜덤 생성
	}
	return 0;
}
