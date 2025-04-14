#include <stdio.h>
#include <stdlib.h>

// 문제 2) 구조체와 동적할당을 같이 사용

typedef struct student
{
	char name[50];
	int age;
	float grade;
} std;

int main(void) {
	int n;
	printf("저장할 학생 수를 입력: ");
	scanf("%d", &n);

	std* ptr = 0;
	ptr = (std*)malloc(sizeof(std) * n); // 학생 수 만큼 할당하기! + 구조체와 동적할당을 같이 사용!
	if (ptr == NULL) {
		printf("메모리가 할당되지 않았습니다.\n");
		return 1;
	}
	

	for (int i = 0; i < n; i++)
	{
			printf("학생 %d의 이름 입력: ",i+1);
			scanf("%s", ptr[i].name);
			while (getchar() != '\n');

			printf("학생 %d의 나이 입력: ",i+1);
			scanf("%d",&ptr[i].age);
			while (getchar() != '\n');

			printf("학생 %d의 성적 입력: ",i+1);
			scanf("%f", &ptr[i].grade);
			while (getchar() != '\n');

	}

	printf("--- 학생 정보 출력 ---");
	for (int i = 0; i < n; i++) {
			printf("\n학생 %d의 이름 = %s, 나이 = %d, 성적 = %.1f",
				i+1,ptr[i].name, (ptr + i)->age, (ptr + i)->grade);
	}
	free(ptr);
	return 1;
}