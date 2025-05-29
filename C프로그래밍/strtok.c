#include <stdio.h>
#include <string.h>

int main(void){
	// 문자열 분리 함수 (문자열, 분리 기준)
	char s[] = "chw-010 9036 3772-cs student";
	char *ptr;
        // ": " 이렇게 하면 :으로도 짜르고 빈칸으로도 분리할  수 있음!
	ptr = strtok(s,"-"); // s에서 '-'을 기준으로 분리하기
	while(ptr != NULL){ 
		printf("%s\n",ptr);
		ptr = strtok(NULL,"-"); // 이전에 자르던 문자열의 다음 조각을 반환
	}
	return 0;
}
	
