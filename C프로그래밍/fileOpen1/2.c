#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(void){
	int fd1,fd2;
	int n;
	char c;

	// open(파일이름, 방식, 권한);
	fd1 = open("data.txt",O_RDONLY,0); // 파일을 읽기 형식으로 열기
	fd2 = open("2.txt", O_WRONLY | O_CREAT, 0644); // 파일을 쓰기로 열기 파일이 없으면 생성 하기, 0644 -> owner=읽고쓰기, 그룹이랑 다른 사람=읽기만 

	// data에 있는 거를 2로 한글자 씩 쓰기
	while((n= read(fd1,&c,1)) > 0 ) {
	        if (write(fd2,&c,1) != 1){
	        	perror("write"); // 에러나면 메시지 출력	
		}
	}
	return 0;
}
