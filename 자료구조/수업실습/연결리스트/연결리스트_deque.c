#include <stdio.h>
#include <stdio.h>
#include <malloc.h>

typedef int element;

typedef struct {
	element data;
	struct DequeueNode* link;
}DequeueNode;

typedef struct {
	DequeueNode* rear;
	DequeueNode* front;
}LinkedDequeueType;

// 초기화 함수
void init(LinkedDequeueType* d) {
	d->rear = NULL;
	d->front = NULL;
}

// 비어있는지 여부 확인 함수
int is_empty(LinkedDequeueType* d) {
	return ((d->front == NULL) && (d->rear == NULL));
}

// 뒤에서 추가
void add_rear(LinkedDequeueType* d, element data) {
	DequeueNode* tmp = (DequeueNode*)malloc(sizeof(DequeueNode));
	tmp->data = data;
	tmp->link = NULL;

	if (is_empty(d)) {
		d->front = tmp;
		d->rear = tmp;
	}
	else {
		d->rear->link = tmp;
		d->rear = tmp;
	}
}

// 앞에서 삭제
int delete_front(LinkedDequeueType* d) {
	DequeueNode* tmp = d->front;
	if (is_empty(d)) {
		printf("큐가 비어있습니다.");
		exit(1);
	}
	else {
		element data = tmp->data;
		d->front = tmp->link;
		if (d->front == NULL) {
			d->rear = NULL;
		}
		free(tmp);
		return data;
	}
}

// 앞에서 추가
void add_front(LinkedDequeueType* d, element data) {
	DequeueNode* tmp = (DequeueNode*)malloc(sizeof(DequeueNode));
	tmp->data = data;
	tmp->link = NULL;

	if (is_empty(d)) {
		d->front = NULL;
		d->rear = NULL;
	}
	else {
		tmp->link = d->front->link;
		d->front = tmp;
	}
}

// 뒤에서 삭제
int delete_rear(LinkedDequeueType* d) {
	DequeueNode* tmp = d->front;
	if (is_empty(d)) {
		printf("dequeue가 비어 있습니다. 삭제 불가능");
		exit(1);
	}
	else {
		int data;
		DequeueNode* current = d->front;
		DequeueNode* pre = NULL;


		while (current -> link != NULL) { // 끝까지 이동
			pre = current;
			current = current->link;
		}
		
		data = current->data;
		if (pre == NULL) {
			// 노드가 하나뿐인 경우
			d->front = d->rear = NULL;
		}
		else {
			pre->link = NULL;
			d->rear = pre;
		}

		free(current);
		return data;
	}
}

// 출력 함수
void print_deque(LinkedDequeueType* d) {
	DequeueNode* p = d->front;
	printf("[FRONT] ");
	while (p != NULL) {
		printf(" %d ", p->data);
		p = p->link;
	}
	printf(" [REAR]\n");
}

// 테스트 main 함수
int main(void) {
	LinkedDequeueType dq;
	init(&dq);

	add_front(&dq, 10);
	add_front(&dq, 20);
	add_rear(&dq, 30);
	add_rear(&dq, 40);
	print_deque(&dq);  // 예상: 20 10 30 40

	printf("앞 삭제: %d\n", delete_front(&dq));  // 20
	printf("뒤 삭제: %d\n", delete_rear(&dq));   // 40
	print_deque(&dq);  // 예상: 10 30

	return 0;
}