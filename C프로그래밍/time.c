#include <stdio.h>
#include <time.h>

int main(void)
{
    time_t t;
    struct tm *tt;

    t = time(NULL); // 1970년 1월 1일 이후 부터 지금 까지의 초
    printf("%ld\n", (long)t);

    tt = localtime(&t); 
    printf("%d %d %d %d %d %d\n", 
           tt->tm_year + 1900, 
           tt->tm_mon + 1, 
           tt->tm_mday, 
           tt->tm_hour, 
           tt->tm_min, 
           tt->tm_sec);

    // 문자열로 표현된 시간 출력 (자기가 지정된 형식으로 찍어줌)
    printf("%s\n", asctime(tt));

    // strftime 사용 예시
    char s[50];
    strftime(s, sizeof(s), "%Y %b %d %H %M %S", tt); // 자기가 원하는 포멧으로 찍기
    printf("%s\n", s);

    return 0;
}

