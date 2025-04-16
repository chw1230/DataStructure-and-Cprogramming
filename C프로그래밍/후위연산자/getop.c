#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // isdigit( ) 사용을 위해서

#define NUMBER '0'

int getch(void);
void ungetch(int);


int getop(char s[]) {
	int i,c;
	
	while((s[0] = c =getch()) == ' ' || c == '\t') {
		; // ' ' 와  '\t' 넘어가기
	}

	s[1] = '\0';
	if (!isdigit(c) && c !='.'){
		return c; // 숫자가 아니거나 '.'이 아닌 경우 그대로 반환
		// 이 함수를 호출하는 곳에서 연산자인 경우 이상한 문자인 경우로 나누어서 처리!
	}
	i = 0; // 매개변수로 전달된 배열에서 저장할 인덱스 번호 역할을 하는 변수
	if (isdigit(c)){
		// 숫자인 경우 배열에 값을 저장
		while(isdigit(s[++i] = c =getch()))
			;
	}

	if (c == '.'){
		while (isdigit(s[++i] = c = getch()))
			;
	}
	s[i] = '\0';
	if ( c!= EOF ){
		ungetch(c);
	}
	// 마지막에 숫자가 아닌 문자를 하나 더 읽게 됨 ungetch로 다시 되돌려 놓기
	return NUMBER; //  숫자임을 인식할 수 있는 값 반환

}

