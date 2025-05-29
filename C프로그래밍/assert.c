#include <stdio.h>
#include <assert.h>

int main(void){
	int i;

	printf("Input positive integer: ");
	scanf("%d",&i);

	assert(i > 0); // 이 조건을 만족하는 경우에만 아래로 내려감!

	printf("You engtered %d Thanks.\n",i);

	return 0;
}
