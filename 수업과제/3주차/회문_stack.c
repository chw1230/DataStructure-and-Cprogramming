#include <stdio.h>

/*
3주차 과제 회문 스택 사용 회문이란 앞뒤 어느 쪽에서 읽어도 같은 단어를 의미
ex> “eye”, “Madam, I’m Adam”, “race car”등이다. 여기서 구두점이나 스페이스, 대소문자 등은 무시
스택을 이용하여 주어진 문자열이 회문인지 아닌지를 결정하는 프로그램을 작성
*/

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
	} else {
		s->data[++(s->top)] = n;
	}
}

int pop(Stack* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		return;
	} else {
		return s->data[(s->top)--];
	}
}

int palindrome(char c[]) { // 소문자만 있는 수정된 배열을 받기
	Stack s;
	init_stack(&s);

	int len = strlen(c);
	int i;
	// 스택에 넣기
	for (i = 0; i < len/2; i++)
	{
		push(&s, c[i]);
	}

	if (len % 2) {
		// 홀수인 경우
		for (i = 1; i <= len / 2; i++)
		{
			if (pop(&s) != c[len / 2 + i]) {
				return 0;
			}
		}
	} else {
		// 짝수인 경우
		for (i = 0; i < len / 2; i++)
		{
			if (pop(&s) != c[len / 2 + i]) {
				return 0;
			}
		}
	}
	return 1;
}

int main(void) {
	char c[MAX_STACK_SIZE];
	fgets(c, MAX_STACK_SIZE, stdin);

	// 기존의 배열을 소문자이고, 공백과 다른 문자들(구두점 등)을 제외한 문자열로 수정하기
	int len = strlen(c);
	int cnt = 0;
	for (int i = 0; i < len; i++)
	{ // 아스키 코드를 통한 비교
		if (('a' <= c[i]) && (c[i] <= 'z')) {
			c[cnt] = c[i];
			cnt++;
		} else if (('A' <= c[i]) && (c[i] <= 'Z')) {
			c[cnt] = c[i] + 32;
			cnt++;
		}
	}
	c[cnt] = '\0'; // 필요한 요소들로만 문장을 가공하고 마지막에 문장을 끝을 의미하는 것

	if (cnt == 0) { // 스페이스바만 누른 경우 + 엔터를 그냥 바로 누른 경우 -> 끝내기
		printf("회문이 아닙니다.");
		return 0;
	}

	if (palindrome(c)) {
		printf("회문입니다.");
	} else {
		printf("회문이 아닙니다.");
	}
	return 0;
}