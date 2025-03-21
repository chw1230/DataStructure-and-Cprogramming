#include <stdio.h>
#include <stdlib.h>

// 문제 1) 정수 배열 동적 할당

int main(void) {
	int N;
	printf("정수 배열 크기 입력: ");
	scanf("%d", &N);

	int* arr = (int*)malloc(sizeof(int) * (N+1));
	if (arr == NULL)
	{
		printf("메모리가 할당되지 않았습니다.\n");
		return 1;
	}
	for (int i = 0; i < N; i++)
	{
		arr[i] = i + 1;
	}

	printf("배열 내용: ");
	for (int i = 0; i < N; i++)
	{
		printf("%d ",arr[i]);
	}
	free(arr);
	return 1;
}