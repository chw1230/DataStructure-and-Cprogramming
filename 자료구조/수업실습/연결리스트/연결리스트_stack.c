#include <stdio.h>
#include <malloc.h>

typedef int element;

typedef struct {
	element data;
	struct StackNode* link;
} StackNode;

typedef struct {
	// 연결리스트들을 담을 스택
	StackNode *top;
} LinkedStackType;

// 초기화 함수
void init(LinkedStackType* s) {
	s->top = NULL;
}

// 공백 상태 검출 함수
int is_empty(LinkedStackType* s) {
	return (s->top == NULL);
}

// push 삽입 함수
void push(LinkedStackType* s, element data) {
	StackNode* tmp = (StackNode*)malloc(sizeof(StackNode));
	tmp->data = data;
	tmp->link = s->top; // 새로 추가한 노드가 스택의 기존의 가장 위에있는 노드를 가리키도록하기
	s->top = tmp; // 추가로 인해 top이 가리키는 노드 변경해주기
}

// pop 제거 함수
element pop(LinkedStackType* s) {
	if (is_empty(s)) {
		printf("스택이 비어있음\n");
		exit(1);
	}
	else {
		StackNode* tmp = s->top; // pop할 값을 tmp에 저장
		int save = tmp->data; // pop할 노드의 값을 save에 저장, 반환을 위해서
		s->top = s->top->link;
		free(tmp);
		return save;
	}
}

// 스택의 노드들의 값 출력하는 함수
void print_stack(LinkedStackType* s) {
	for (StackNode* p = s->top; p != NULL; p = p->link) {
		/*if (p->link != NULL) {
			printf(" -> ");
		}*/
		printf("%d -> ", p->data);
	}
	printf("NULL\n");
}

int main(void) {
	LinkedStackType s;
	init(&s);
	push(&s, 1); print_stack(&s);
	push(&s, 2); print_stack(&s);
	push(&s, 3); print_stack(&s);
	int popData = 0;
	popData = pop(&s);
	printf("%d 삭제 : ", popData);
	print_stack(&s);
	popData = pop(&s); 
	printf("%d 삭제 : ", popData);
	print_stack(&s);
	popData = pop(&s); 
	printf("%d 삭제 : ", popData);
	print_stack(&s);
}