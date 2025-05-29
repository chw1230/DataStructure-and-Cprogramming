#include <stdio.h>
#include <stdlib.h>

int main(void){
	long l;
	char *s = "1234";

	// char *s = "0x1234"; 또는 l = strtol(s,NULL,16); -> 16진수로 읽기
	
	// char *s = "1234" 또는 l = strtol(s,NULL,0); -> 2진수로 읽기

	// long strtol(const char *s, char **endp, int base) 
	// 문자열 s를 long으로 바꾸는 함수
	// base => 몇 진수로 할 것인지
	// endp => 변환 후의 문자열의 시작 주소 담을 포인터

	l = strtol(s,NULL,8); // 8진수로 읽기
	printf("%lx %lo %ld\n",l,l,l );
	return 0;
}
