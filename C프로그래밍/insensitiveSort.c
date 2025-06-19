#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFSIZE 256
#define MAXINFO 100

typedef struct {
	char name[100];
	char num[100];
	char memo[100];
} Info;

// 대소문자 구분 없이 문자열 비교 함수
int caseInsensitiveCompare(const void* a, const void* b) {
	const Info* pa = (const Info*)a;
	const Info* pb = (const Info*)b;

	const char* s1 = pa->name;
	const char* s2 = pb->name;

	while (*s1 && *s2) {
		char c1 = tolower(*s1);
		char c2 = tolower(*s2);
		if (c1 != c2)
			return c1 - c2;
		s1++;
		s2++;
	}
	return tolower(*s1) - tolower(*s2);
}

// 시험 후 리펙토링 함수
int main(void) {
	FILE* f = fopen("data.txt", "r");
	if (!f) {
		perror("파일 열기 실패");
		return 1;
	}

	Info info[MAXINFO];
	int cnt = 0;
	char line[BUFSIZE];

	while (fgets(line, BUFSIZE, f)) {
		char* name = strtok(line, ":");
		char* num = strtok(NULL, ":");
		char* memo = strtok(NULL, "\n");

		if (name && num && memo) {
			strcpy(info[cnt].name, name);
			strcpy(info[cnt].num, num);
			strcpy(info[cnt].memo, memo);
			cnt++;
		}
	}

	fclose(f);

	// 이름 기준 대소문자 무시 정렬
	qsort(info, cnt, sizeof(Info), caseInsensitiveCompare);

	// 출력
	printf("이름\t전화번호\t\t메모\n");
	for (int i = 0; i < cnt; i++) {
		printf("%s\t%s\t%s\n", info[i].name, info[i].num, info[i].memo);
	}

	return 0;
}
