#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(void)
{
    int fd1, fd2;
    int n;
    char buf[BUFSIZ]; // 표준 입출력에서 기본으로 정의된 기본 버퍼 크기

    fd1 = open("data.txt", O_RDONLY, 0); // 읽기 전용으로 열기
    fd2 = open("3.txt", O_WRONLY | O_CREAT, 0644); // 쓰기 + 없으면 생성

    // 앞의 꺼(2.c)와 는 다르게  버퍼 단위로 복사
    while ((n = read(fd1, buf, BUFSIZ)) > 0) {
        if (write(fd2, buf, n) != n)
            perror("write"); // 쓰기 실패 시 에러 메시지
    }

    return 0;
}

