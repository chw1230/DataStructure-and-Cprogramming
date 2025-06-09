#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFSIZE 256 // 이 길이 만큼 읽기
#define MAXINFO 100 // 최대 100명의 정보 다루기
// 연락처 구조체
typedef struct {
	char name[100];
	char num[100];
	char memo[100];
} Info;

int compare_name(const void *name1, const void *name2){ 
	// 이름 오름차순 정렬을 위한 함수
	return strcmp(((Info *)name1) -> name, ((Info *)name2)->name);
} 

int compare_name_R(const void *name1, const void *name2){ 
	// 이름 내림차순 정렬을 위한 함수
	return strcmp( ((Info *)name2)->name, ((Info *)name1) -> name );
}

int compare_num(const void *num1, const void *num2){
	// 번호 오름차순 정렬을 위한 함수
	return strcmp(((Info*)num1) -> num,((Info*)num2)->num);
}

int compare_num_desc(const void *num1, const void *num2){
	// 번호 내림차순 정렬을 위한 함수
	return -1*strcmp(((Info*)num1) -> num,((Info*)num2)->num);
}

int main(void){

	FILE * f = fopen("data.txt","r"); // data.txt 파일에서 일기모드로 읽어오기
	char line[BUFSIZE];
	int cnt = 0; // 사람의 수를 의미하는 변수
	Info info[MAXINFO]; // Info 구조체를 담을 수 있는 배열 생성

	while(fgets(line,BUFSIZE,f)){ // BUFSIZE 만큼 파일에서 읽어와서 배열에 넣기 다 읽은 상태가 된다면 NULL을 반환 -> while 중지
		char *name = strtok(line,":"); // 문자열을 ":"로 구분하기
		char *num = strtok(NULL,":"); // NULL의 의미 -> 이전에 strtok()으로 자른 부분에서 계속 자르겠다는 뜻 ":" 다음 부터 시작, ":"로 또 나누기
		char *memo = strtok(NULL,":"); // ":" 이후 부터 마지막 memo나오고 "\n"나오는 지점까지 구분하기
	
		if (name && num && memo) { 
			// Info 배열에 있는 구조체에 접근하여 각각의 정보에 맞게 복사해 넣기
			strcpy(info[cnt].name, name);
			strcpy(info[cnt].num, num);
			strcpy(info[cnt].memo, memo);	
			cnt++; 
		}
	}

	fclose(f); // 파일 닫기
	

	qsort(info, cnt, sizeof(Info), compare_name);
	// qsort(info, cnt, sizeof(Info), compare_num_desc); // 번호 정렬
	
	printf("이름 전화\t 메모\n");
  	for (int i = 0; i < cnt; i++) {
		printf("%s %s %s", info[i].name, info[i].num, info[i].memo);
    	}
	return 0;
}

