/*
옵션없이 수행되면 사용법을 안내
-l 옵션이 주어지면 이름 알파벳순으로 정렬하여 모든 데이터를 출력
검색어가 주어지면 검색어가 들어있는 레코드 들을 출력
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MaxLine 500 
#define MaxInfo 100

// 사용자의 정보를 담을 구조체
typedef struct {
	char name[50];
	char num[50];
	char memo[50];
}Info;

// 이름을 통한 비교를 위한 함수(오름차순)
int compare_name(const void * name1, const void * name2){
	return strcmp(((Info *)name1) -> name,((Info *)name2) -> name );
}


// 이름을 통한 비교를 위한 함수(내림차순)
int compare_name_R(const void * name1, const void * name2){
	return -1*strcmp(((Info *)name1) -> name,((Info *)name2) -> name );
}

// 사용자의 정보 개수
int InfoCnt = 0;

int main(int argc, char *argv[]){
	// 파일을 읽기 형식으로 열기
	FILE *f = fopen("1.txt","r");
	if (!f) {
   		 perror("파일 열기 실패");
	return 1;
	}

	// ./1 만 입력된 경우 -> 사용법 출력
	if ( argc == 1){
		printf("Usage:./1 -l or pattern\n");
		return 0;
	} 
	
	Info info[MaxInfo]; // 구조체를 담을 배열 생성
	char line[MaxLine]; // 파일에서 글자을 읽어와 잠시 저장할 배열 생성
	while (fgets(line,sizeof(line),f)) {
		// ":" 형식으로 분리하여 읽기
		char * name = strtok(line,":");
		char * num = strtok(NULL,":");
		char * memo = strtok(NULL,":");
		
		// memo에서 "\n"이 나오는 위치를 반환 => 인덱스로 이용하여 널문자 넣기
		memo[strcspn(memo, "\n")] = 0;

		// 구조체의 값에게 붙여 넣기
		strcpy(info[InfoCnt].name ,name);
		strcpy(info[InfoCnt].num,num);
		strcpy(info[InfoCnt].memo,memo);
	        InfoCnt++;
	}
	fclose(f);
	
	if (  strcmp(argv[1], "-l") == 0){
		// 이름 알파벳순으로 정렬하고 모든 데이터 출력
		qsort(info,InfoCnt,sizeof(Info),compare_name);
		for (int i =0;i<InfoCnt;i++){
			printf("%s %s %s\n",info[i].name,info[i].num,info[i].memo);
		}
	} else if ( strcmp(argv[1],"-r") == 0 ) {
		// 이름을 알파벳 역순 정렬
		qsort(info, InfoCnt, sizeof(Info), compare_name_R);	
                for (int i =0;i<InfoCnt;i++){
                        printf("%s %s %s\n",info[i].name,info[i].num,info[i].memo);
                }

	} else {
		// 검색어 주어지면 검색어가 들어있는 레코드들을 출력
		for (int i =0;i<InfoCnt;i++){
			if ( strstr(info[i].name,argv[1]) || strstr(info[i].num,argv[1]) || strstr(info[i].memo,argv[1])){
				printf("%s %s %s\n",info[i].name,info[i].num,info[i].memo);
			}
                }
	}
	return 0;
}
