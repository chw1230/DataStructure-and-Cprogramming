#include <stdio.h>
#include <string.h>

#define BUFSIZE 256 // 이 길이 만큼 읽기

int main(void){
	FILE * f = fopen("data.txt","r"); // data.txt 파일에서 일기모드로 읽어오기
	printf("이름 전화\t 메모\n");
	char line[BUFSIZE];

	while(fgets(line,BUFSIZE,f)){ // BUFSIZE 만큼 파일에서 읽어와서 배열에 넣기 다 읽은 상태가 된다면 NULL을 반환 -> while 중지
		char *name = strtok(line,":"); // 문자열을 ":"로 구분하기
		char *num = strtok(NULL,":"); // NULL의 의미 -> 이전에 strtok()으로 자른 부분에서 계속 자르겠다는 뜻 ":" 다음 부터 시작, ":"로 또 나누기
		char *memo = strtok(NULL,"\n"); // ":" 이후 부터 마지막 memo나오고 "\n"나오는 지점까지 구분하기
		
		if (name && num && memo) { // 3개중 하나리ㅏ도 이상한 지점이 있으면 출력 못하도록 하기
			printf("%s %s %s\n",name,num,memo);
		}
	}

	fclose(f); // 파일 닫기
	return 0;
}

