#include <stdio.h>

struct employee 
{
	char name[20];
	char number[14];
	int n;
};

int main_b(void) {
	struct employee emp;
	printf("이름 입력: "); 
	scanf("%s", emp.name);

	printf("\n주민 등록 번호 입력: ");
	scanf("%s", emp.number);

	printf("\n급여 입력: ");
	scanf("%d", &(emp.n));

	printf("이름: %s\n", emp.name);
	printf("주민 등록 번호 : %s\n", emp.number);
	printf("급여 : %d",emp.n);
	return 0;
}