#include <stdio.h>

#define MAXVAL 100  /* stack의 최대를 정의하기  */

int sp = 0;         /* 비어있는 스택 위치(인덱스)를 의미하는 sp 변수 */
double val[MAXVAL]; /* MAXVAL을 배열의 길이로 하는 스택역할의 배열 생성  */

/* 매개변수를 배열에 넣는 push  */
void push(double f)
{
    if (sp < MAXVAL) {
        val[sp++] = f; // 비어있는 스택 위치(인덱스)에 값을 넣고 sp(인덱스) 하나 올려주기
    } else {
        printf("error: stack full, can't push %g\n", f);
    }
}

/* 배열에 있는 값을 반환해주어 pop역할을 하는 함수 */
double pop(void)
{
    if (sp > 0) { // 배열에 값이 존재하는 경우
        return val[--sp]; // 비어있는 인덱스를 의미하는 sp를 하나 줄이고 값을 반환!
    } else {
        printf("error: stack empty\n");
        return 0.0;
    }
}
