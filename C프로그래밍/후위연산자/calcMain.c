#include <stdio.h> 
#include <stdlib.h>
#include <ctype.h>

#define MAXOP 100
#define NUMBER '0'

int getop(char[]);
void push(double);
double pop(void);

/* postfix calculator  */
int main(void){
	int type;
	double op2;
       	char s[MAXOP];
	while ((type = getop(s)) !=  EOF) {
		switch (type) {
			case NUMBER:
				push(atof(s)); // 숫자인 경우 문자열을 실수로 반환해서 push를 통해 배열에 넣기
			       	break;
			case '+':
		      		push(pop() +  pop()); // '+'인 경우 배열에서 2개를 빼고 더하기 계산을 해서 다시 넣기
				break;
			case '*':
				push(pop() *  pop()); // '*'인 경우 배열에서 2개를 빼고 곱하기 계산을 해서 다시 넣기
				break; 
			case '-':
				op2 = pop();  // 먼저 pop한 수를 빼주기 위해서 op2에 저장하기
				push(pop() - op2); // 그 다음 뺀수에 저장한 값을 빼고 다시 넣어주기
				break;
			case '/':
				op2 =  pop(); // '-'와 동일하게 처리!
			       	if (op2 != 0.0) { // 0으로 나누는 경우 고려하기
					push(pop() / op2);
				} else {
					printf("error: zero divisor\n");
				}
				break;
			case '\n':
				printf("\t%.8g\n", pop()); // 입력하고 엔터를 눌렀을 때를 종료로 생각하고 마지막에 하나 남아있을 최종 계산 값을 pop하기 
			       	break;
			default:
				// 숫자 연산자를 제외한 이상한 문자들은 오류 메시지 띄우기
				printf("error: unknown command %s\n", s);
				break;
			}
	}
	return 0;
}
