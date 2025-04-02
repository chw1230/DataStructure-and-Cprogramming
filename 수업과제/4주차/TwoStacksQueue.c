#include <stdio.h>
#define MAX_STACK_SIZE 100

/*
* 2개의 Stack을 이용해 Queue처럼 작동하는 자료구조를 구현
* 입력 스택 (stack_in): 데이터를 집어넣을 때 사용하는 스택
* 출력 스택 (stack_out): 데이터를 꺼낼 때 사용하는 스택
*/

typedef int element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} Stack;

// 스택 초기화 함수
void init_Stack(Stack* stack) {
	stack->top = -1;
}

// 스택 비어있는 지 확인
int is_empty(Stack* stack) { 
	return (stack->top == -1);
}

// 스택이 가득 찼는지 확인
int is_full(Stack* stack) { 
	return (stack->top == (MAX_STACK_SIZE - 1));
}

void push(Stack* stack,int value) {
	stack->data[++(stack->top)] = value;
}

int pop(Stack* stack) {
	return stack->data[(stack->top)--];
}

// Queue 구조체 정의하기
typedef struct {
	// 큐를 이루는 2개의 스택으로 구성하기!
	Stack stack_in;  
	Stack stack_out; 
} Queue;

// 큐 초기화하기
void init_Queue(Queue* queue) {
	init_Stack(&(queue->stack_in));
	init_Stack(&(queue->stack_out));
}

// 큐에 데이터 추가하기
void enqueue(Queue* queue, int value) {
	if (is_full(&(queue->stack_in))) {// 큐 가득 찼는지 확인하기
		printf("%d 입력 실패, 입력 스택이 가득찼습니다.(= 큐가 가득 찼습니다.)\n",value);
		return 0;
	}
	printf("%d 입력 성공\n", value);
	push(&(queue->stack_in), value); // 입력 스택으로 데이터 추가
}

// 큐에서 데이터 제거하기
int dequeue(Queue* queue) {
	int save; 

	if (!is_empty(&(queue->stack_in)) && is_empty(&(queue->stack_out))) { // 입력 스택 존재하고, 출력 스택이 비어있는 경우
		while (!is_empty(&(queue->stack_in))) { 
			// 입력 스택에 있는 모든 값을 출력 스택으로 옮기기
			save = pop(&(queue->stack_in));
			push(&(queue->stack_out), save);
		}
	}

	if (!is_empty(&(queue->stack_out))) { // 출력 스택에 값이 존재하는 경우
		printf("반환값 : %d\n", pop(&(queue->stack_out)));
	}
	else { // 출력 스택에 값이 존재하지 않는 경우 
		// 입력 스택의 값을 모두 옮기는 과정을 거쳤기 때문에
		// 여기서도 출력 스택이 비면 입력 스택도 애초에 아무 것도 없었다고 생각할 수 있음!
		printf("큐가 비어 있습니다.");
		return 0;
	}
}


int main(void) {
	Queue queue;

	init_Queue(&queue);
	printf("10,20,30 enqueue 하기\n");
	enqueue(&queue, 10);
	enqueue(&queue, 20);
	enqueue(&queue, 30);

	printf("\ndequeue 2번 실행\n");
	dequeue(&queue);
	dequeue(&queue);

	printf("\n40 enqueue 하기\n");
	enqueue(&queue, 40);

	printf("\ndequeue 2번 실행\n");
	dequeue(&queue);
	dequeue(&queue);

	printf("\n비어있는 상태에서 dequeue 실행하기\n");
	dequeue(&queue);
}

