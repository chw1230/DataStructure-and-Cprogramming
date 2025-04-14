
#include <stdio.h>

#define MAX_STACK_SIZE 100
typedef int element;

typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} Stack;

void init_stack(Stack * s) {
	s->top = -1;
}

int is_empty(Stack* s) { // 기초 값인 -1과 top이 같다면 배열이 비어있는 상태임! 
	return (s->top == -1);
}

int is_full(Stack* s) { // 스택의 최대 배열과 top이 같다면 스택이 가득 찬 상태임!
	return (s->top == (MAX_STACK_SIZE -1));
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

int main(void) {
	Stack s;

	init_stack(&s); // 스택 초기화

	push(&s, 1);
	push(&s, 2);
	push(&s, 3);

	printf("%d\n",pop(&s));
	printf("%d\n",pop(&s));
	printf("%d",pop(&s));
}
