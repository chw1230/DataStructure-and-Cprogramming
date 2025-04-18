#include <stdio.h>
#include <malloc.h>

typedef int element;

typedef struct {
	element data;
	struct QueueNode* link;
} QueueNode;

typedef struct {
	// 연결리스트들을 담을 스택
	QueueNode* front;
	QueueNode* rear;
} LinkedQueueType;

void init(LinkedQueueType* q) {
	q->front = NULL;
	q->rear = NULL;
}

int is_empty(LinkedQueueType* q) {
	return (q->front == NULL);  // 더 간단하고 직관적
}

void enqueue(LinkedQueueType* q, element data) {
	QueueNode *tmp = (QueueNode*)malloc(sizeof(QueueNode));
	tmp->data = data;
	tmp->link = NULL;

	if (is_empty(q)) {
		q->front = tmp;
		q->rear = tmp;
	}
	else {
		q->rear->link = tmp;
		q->rear = tmp;
	}
}

int dequeue(LinkedQueueType* q) {
	QueueNode* tmp = q->front;
	if (is_empty(q)) {
		printf("큐가 비어있습니다.");
		exit(1);
	}
	else {
		element data = tmp->data;
		q->front = q->front->link;
		if (q->front == NULL) { // 큐에 노드가 하나만 남아있었던 상황
			q->rear = NULL; // rear를 NULL 로 만드는 이유는 free에서 할당이 해제되어도 rear는 계속해서 rear가 기존의 가지고 있던 주소 값을 가지고 있게된다!
		}
		free(tmp);
		return data;
	}
}

void print_queue(LinkedQueueType* q) {
	element data;
	QueueNode* qq = q->front;

	while (qq != NULL) {
		data = qq->data;
		printf(" | %d | ", data);
		qq = qq->link;
	}
}

// ✨ 테스트용 main 함수
int main(void) {
	LinkedQueueType q;
	init(&q);

	printf("큐에 10, 20, 30을 삽입합니다.\n");
	enqueue(&q, 10);
	enqueue(&q, 20);
	enqueue(&q, 30);
	print_queue(&q);
	printf("\n");

	printf("큐에서 데이터를 하나씩 꺼냅니다:\n");
	while (!is_empty(&q)) {
		printf("꺼낸 값: %d\n", dequeue(&q));
	}

	printf("큐에서 더 꺼내면?\n");
	dequeue(&q);  // 빈 큐에서 꺼내는 상황

	return 0;
}