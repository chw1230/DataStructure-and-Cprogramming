#include <stdio.h>
#define BUFSIZE 100

char buf[BUFSIZE];   /* ungetch에 사용될 배열 */
int bufp = 0;        /* buf배열에서 넣거나 꺼내는 위치를 알려주는 인덱스  */

int getch(void) {    
       	// 인덱스가 가리키는게 있다면(bufp > 0) 가리키는 것을 반환하고 아니라면 새로입력받기
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)  // 매개변수로 전달된 값을 버퍼 배열에 넣는 함수
{
    // 이 함수를 호출하는 곳에서 특정조건일때 ungetch(값) 이렇게 사용되는 것!
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
