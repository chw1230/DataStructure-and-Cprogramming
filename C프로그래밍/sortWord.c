#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int compare_str(const void * a,const void *b){
	return strcmp(*(char**)a, *(char **)b);
}

int compare_str_desc(const void *a, const void *b) {
    return strcmp(*(char **)b, *(char **)a);  // 역순(-r)
}



int main(int argc,char *argv[]){
	if ( argc < 2 ) {
		printf("프로그램 실행 조건을 충족하지 않았습니다.");
		return 0;
	}

	int r = 0; // -r의 여부 저장할 변수
	int startIdx = 1; // 시작하는 인덱스 변수를 담은 변수

	if (strcmp(argv[1],"-r") == 0) {
		r = 1; // r옵션 활성화
		startIdx = 2;

		if (argc <= 2){
			printf("프로그램 실행 조건을 충족하지 않습니다.");
			return 0;
		}
	}

	int cnt = argc - startIdx; 
	char **words = &argv[startIdx]; // ./파일명 옵션을 제외한 순수한 문자시작하는 위치를 넘겨주기

	qsort(words, cnt,sizeof(char*), r ? compare_str_desc : compare_str);

	for ( int i = 0; i< cnt ; i++){
		printf("%s ",words[i]);
	}
	return 0;
}
