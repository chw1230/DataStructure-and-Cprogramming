#include <stdio.h>
#define MAX_LINE 32


void tenTOtwo(int n){
	int arr[MAX_LINE];
	int i = 0;

	while ( n != 0 ){
		arr[i] = n % 2;
		n = n / 2;
		i++;
	}
	
	for (int j = i-1 ; j >= 0 ;j--){
		printf("%d",arr[j]);
	}
}

int main(void) {
	int n;
	printf("10진수를 입력: ");
	scanf("%d",&n);

	tenTOtwo(n);
	return 1;
}
