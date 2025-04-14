#include <stdio.h>
/*
 * 반복문을 사용한 피보나치 만들어보기!
 */
		
int main(void) {
	int i;
	int arr[21];
	arr[1] = 1;
	arr[2] = 1;
	
	// 저장
	for (i = 3; i<= 20;i++){
		arr[i] = arr[i-1] + arr[i-2];
	}

	// 출력
	for (int i = 1; i <=20 ;i++){
		printf("%d : %d\n",i,arr[i]);
	}
}
