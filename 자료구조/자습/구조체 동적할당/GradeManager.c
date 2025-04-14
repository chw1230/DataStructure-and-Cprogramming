#include <stdio.h>
#include <stdlib.h>

typedef struct student {
	char name[20];
	int kr;
	int en;
	int math;
	struct student* next;
} Student;

void AddStudent(Student **head, Student **tail,int cnt) {
	if (*head == NULL) {
		*head = (Student*)malloc(sizeof(Student));
		*tail = *head;
	}
	else {
		(*tail) -> next = (Student*)malloc(sizeof(Student));
		*tail = (*tail)->next;
	}

	printf("%d 번째 학생 이름 : ", cnt);
	scanf("%s", (*tail)->name);

	printf("국어 점수 : ");
	scanf("%d", &((*tail)->kr));

	printf("영어 점수 : ");
	scanf("%d", &((*tail)->en));

	printf("수학 점수 : ");
	scanf("%d", &((*tail)->math));
	(*tail)->next = NULL;
}

void PrintStudent(Student** head, Student** tail, int cnt) {
	int* p;
	int i = 0;
	printf("\n-----------------------------------\n");
	printf(" 이름  국어 영어 수학 총점 평균\n");
	printf("-----------------------------------");
	while (*head != NULL)
	{
		p = *head;
		int sum = (*head)->kr + (*head)->en + (*head)->math;
		printf("\n %s   %d   %d   %d   %d   %d", (*head)->name, (*head)->kr, (*head)->en, (*head)->math, sum,sum/3);
		*head = (*head)->next;
		free(p);
	}
	printf("\n");
}

int main(void) {
	Student* head = NULL;
	Student* tail = NULL;
	int cnt = 0;
	int n;
	while (1) {
		printf("\n[메뉴]");
		printf("\n1. 성적 입력");
		printf("\n2. 성적 확인");
		printf("\n3. 종료");
		printf("\n번호 입력하기 : ");
		scanf("%d", &n);

		if (n == 1) {
			cnt++;
			AddStudent(&head, &tail,cnt);
		}
		else if (n == 2) {
			PrintStudent(&head, &tail, cnt);
		}
		else if (n == 3) {
			printf("프로그램이 종료됨");
			return 1;
		}
		else {
			printf("잘못된 입력입니다.\n");
		}
	}
}