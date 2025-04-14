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

int check_matching(const char* c) { // 주소를 넘겨 받을 수 있는 char *c 생성
	Stack s;
	init_stack(&s);
	int len = strlen(c);

	for (int i = 0; i < len; i++)
	{
		char ch = c[i];
		switch (ch) {
		case '[': case '{': case'(':
			// switch문의 특징 활용하기
			push(&s, ch);
			break;
		}
		switch (ch) {
		case ']': case '}': case')':
			if (is_empty(&s)) {
				return 0; // 스택이 비어 있는 경우 끝내기 -> 이 경우는 좌측 괄호가 나오지 않고 우측 괄호 부터 나온 경우를 의미!!
			}
			else
			{
				char save = pop(&s);
				if ((save == '[' && ch != ']') || (save == '{' && ch != '}') || (save == '(' && ch != ')')) {
					// 잘못 매칭되는 경우를 의미하므로 실패
					return 0;
				}
			}
			break;
		}
	}

	// 문제 없이 다 돌았다면
	if (!is_empty(&s)) {
		return 0; // 스택이 비어 있지 않으면 / 0은 실패를 의미
	}
	return 1;
}

int main(void) {
	char *p = "{ A[(i+1)]=0; }"; // p는 "문자열"의 주소를 기지고 있음
	if (check_matching(p) == 1) 
		printf("%s 괄호검사성공\n", p);
	else
		printf("%s 괄호검사실패\n", p);
	return 0;
}