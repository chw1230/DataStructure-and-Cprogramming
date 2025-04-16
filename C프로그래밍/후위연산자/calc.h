// calc.h 헤더파일을 사용하는 경우 기존의 코드파일에 #include "calc.h" 추가하기
// 그리고 기존 코드 파일에서 상수 정의한 내용과 함수 선언한 부분들을 없애야함!

#ifndef CALC_H
#define CALC_H

// 상수 정의
#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 100
#define BUFSIZE 100

// 함수 선언
void push(double);
double pop(void);

int getop(char []);
int getch(void);
void ungetch(int);

#endif

