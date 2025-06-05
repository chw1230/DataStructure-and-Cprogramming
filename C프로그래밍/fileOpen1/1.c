#include <stdio.h>

int main(void){
	FILE *fp;
	char str[] ="0123456789";

	fp = fopen("data.txt","w"); // 파일을 쓰기모드로 읽어오기
	// "w"는 파일의 기존 내용을 초기화 하고 덮어쓴다.
	// "a"를 이용해야 기존의 내용에 이어서 쓰는 것!

	for (int i = 0 ;i < 100000; ++i){
		fputs(str,fp); // 파일에 내용을 넣기!
	}

	return 0;
}
