#include <stdio.h>

#define MAX_STACK_SIZE 100
typedef char element;

typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} Stack;

void init_stack(Stack* s) {
	s->top = -1;
}

int is_empty(Stack* s) { // 기초 값인 -1과 top이 같다면 배열이 비어있는 상태임! 
	return (s->top == -1);
}

int is_full(Stack* s) { // 스택의 최대 배열과 top이 같다면 스택이 가득 찬 상태임!
	return (s->top == (MAX_STACK_SIZE - 1));
}

void push(Stack* s, int n) {
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else {
		s->data[++(s->top)] = n;
	}
}

int pop(Stack* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		return;
	}
	else {
		return s->data[(s->top)--];
	}
}

int eval(char exp[]) {
	int n1, n2;
	int len = strlen(exp);

	Stack s;
	init_stack(&s); // 스택 초기화 

	for (int i = 0; i < len; i++)
	{
		char ch = exp[i];
		if (ch != '+' && ch != '-' && ch != '*' && ch != '/') { // ch가 연산자가 아닌 숫자인 경우 스택에 숫자 push하기!
			push(&s, ch - '0');
		}
		else
		{ // ch 연산자인 경우 스택에서 계산하기 위한 숫자 2개를 빼오기 빼온 수를 차례 대로 n1,n2에 넣기  
			n1 = pop(&s);
			n2 = pop(&s);
			switch (ch) {
				case '+':
					push(&s, n1 + n2);
					break;
				case '-':
					// -의 경우 게산 순서 조심하기 스택을 기준으로 생각했을 때 먼저 들어간 수는 n2임! 그러므로 n2-n1 시행하기!
					push(&s, n2 - n1);
					break;
				case '*':
					push(&s, n1 * n2);
					break;
				case '/':
					// /의 경우 게산 순서 조심하기 스택을 기준으로 생각했을 때 먼저 들어간 수는 n2임! 그러므로 n2/n1 시행하기!
					push(&s, n2 / n1);
					break;
			}
		}
	}
	return pop(&s); // 마지막 하나 남아있는 수를 pop을 이용하여 반환해주기
}

int main(void) {
	int result;
	printf("후위표기식은 82/3-32*+\n");
	result = eval("82/3-32*+");
	printf("결과값은 %d\n", result);
	return 0;
}
