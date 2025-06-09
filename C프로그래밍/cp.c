#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

#define PERMS 0666  // rw-rw-rw-

void error(const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    vfprintf(stderr, fmt, args);
    fprintf(stderr, "\n");
    va_end(args);
    exit(1);
}

int main(int argc, char *argv[]){
	int f1, f2, n;
	char buf[BUFSIZ];

	if (argc != 3){ // 인자가 부족한 경우
		error("cp 명령어 사용 불가");
	}
	
	if ((f1 = open(argv[1],O_RDONLY,0)) == -1){ //첫 번째 파일을 열 수 없을 때
		error("%s 첫 번째 파일을 열 수 없습니다.",argv[1]);
	}

	if ((f2 = creat(argv[2],PERMS)) == -1){ // 두 번째 파일이 없는 경우 여기에서 생성됨!
		// int fd = open("file2.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666); -> creat를 대신하는 open 코드
	
		error("%s 파일을 생성 할 수 없습니다.",argv[2]);
	}

	while ( (n = read(f1,buf,BUFSIZ)) > 0){
			if ( write(f2,buf,n) != n){
				error("%s 파일에 쓰기 에러",argv[2]);
			}	
	}
	return 0;
}

// 파일 열기 플래그 정리
// 
// - 파일 접근 모드
// O_RDONLY -> 읽기 전용 열기
// O_WRONLY -> 쓰기 전용 열기
// O_RDWR -> 읽기 쓰기 모두 가능
//
// - 파일 생성/제어 관련 옵션
// O_CREAT -> 파일 없으면 새로 생성
// O_TRUNC -> 기존 내용 모두 비우기
// O_APPEND -> 파일 끝에만 데이터 추가
