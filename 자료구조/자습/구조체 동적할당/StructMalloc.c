#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char title[20];
	char name[20];
	int page;
} manager;

int main(void) {
	manager* ptr = (manager*)malloc(sizeof(manager) * 3);

	printf("도서 정보 입력\n");
	for (int i = 0; i < 3; i++)
	{
		printf("%d번째 책 정보 입력\n",i+1);
		printf("저자: ");
		scanf("%s", (ptr+i)->name);
		printf("제목: ");
		scanf("%s", (ptr + i)->title);
		printf("페이지 수: ");
		scanf("%d", &((ptr + i)->page));
	}

	printf("\n도서 정보 출력\n");
	for (int i = 0; i < 3; i++)
	{
		printf("%d번째 책 정보 출력\n",i+1);
		printf("저자: %s\n", (ptr + i)->name);
		printf("제목: %s\n", (ptr + i)->title);
		printf("페이지 수:%d\n", (ptr + i)->page);
	}
	free(ptr);
}