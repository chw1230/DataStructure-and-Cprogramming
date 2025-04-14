#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

// Circular Queue

typedef int element;

typedef struct {
	int rear, front;
	element data[MAX_QUEUE_SIZE];
} QueueType;

// 초기화 함수 
void init_queue(QueueType* q) {
	q->rear = 0;
	q->front = 0;
}

// 가득차있는 지 확인하는 함수
int is_full(QueueType* q) {
	return q->front == (q->rear + 1) % MAX_QUEUE_SIZE;
}

// 비어 있는지 확인하는 함수
int is_empty(QueueType* q) {
	return (q->front == q->rear);
}

// 삽입 함수 enqueue
void enqueue(QueueType* q,int value) {
	if (is_full(q)) {
		printf("Queue가 가득차있습니다.\n");
		exit(1);
	}

	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = value;
}

// 제거 함수 dequeue
int dequeue(QueueType* q) {
	if (is_empty(q)) {
		printf("Queue가 비어있습니다.");
		exit(1);
	}

	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

// 원형큐 출력 함수
void queue_print(QueueType* q) {
	printf("QUEUE(front=%d rear=%d) = ", q->front, q->rear);

	if (!is_empty(q)) {
		int i = q->front;
		do {
			i = (i + 1) % (MAX_QUEUE_SIZE);
			printf("%d | ", q->data[i]);
			if (i == q->rear) {
				break;
			}
		} while (i != q->front);
	}
	printf("\n");
}

int main(void) {
	QueueType queue;
	int element;

	init_queue(&queue);

	enqueue(&queue, 2);
	enqueue(&queue, 9);
	enqueue(&queue, 3);
	enqueue(&queue, 5);
	queue_print(&queue);
	

	element = dequeue(&queue);
	printf("거낸 정수 : %d\n", element);
	element = dequeue(&queue);
	printf("거낸 정수 : %d\n", element);
	queue_print(&queue);

	enqueue(&queue, 7);
	enqueue(&queue, 8);
	queue_print(&queue);

	element = dequeue(&queue);
	printf("거낸 정수 : %d\n", element);
	element = dequeue(&queue);
	printf("거낸 정수 : %d\n", element);
	queue_print(&queue);

	enqueue(&queue, 1);
	queue_print(&queue);

	
	return 0;
}