#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct {
	int data[MAX_QUEUE_SIZE];
	int rear, front;
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

// 덱의 뒤에 삽입하는 함수 add_rear (= enqueue)
void add_rear(QueueType* q, int value) {
	if (is_full(q)) {
		printf("덱이 가득차있습니다.\n");
		exit(1);
	}

	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = value;
}

// 덱의 앞에서 제거하는 함수 delete_front (=dequeue)
int delete_front(QueueType* q) {
	if (is_empty(q)) {
		printf("덱이 비어있습니다.");
		exit(1);
	}

	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

// 덱의 앞에 삽입하는 함수 add_front
void add_front(QueueType* q,int value) {
	if (is_full(q)) {
		printf("덱이 가득찼습니다.");
		exit(1);
	}

	q->data[q->front] = value; // 값을 넣고
	q->front = (q->front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE; // 반시계 방향으로 이동
	// 왜 front에서 1을 빼고 MAX를 더할까? -> -1 이유 : front의 자리 반 시계로 이동 , + MAX 이유 : 인덱스 0에서 MAX-1로 이동하는 경우를 위해서
	// 왜 % MAX를 할까? -> 인덱스가 1인 경우 -1 하면 0 여기에 +MAX하면 5인데 5인덱스는 없음 MAX를 나누어 0에 위치 시키기 위해서 나머지 숫자들은 5보다 작으니 본래 위치라고 생각하면됨!
}

// 덱의 뒤에 값을 제거하는 함수 delete_rear 
int delete_rear(QueueType* q) {
	if (is_empty(q)) {
		printf("덱이 비있습니다.");
		exit(1);
	}
	int save = q->rear; // rear의 값이 바뀌기 전에 저장해두기
	q->rear = (q->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	// 왜 rear에서 1을 빼고 MAX를 더할까? -> -1 이유 : rear의 자리 반 시계로 이동 , + MAX 이유 : 인덱스 0에서 MAX-1로 이동하는 경우를 위해서
	// 왜 % MAX를 할까? -> 인덱스가 1인 경우 -1 하면 0 여기에 +MAX하면 5인데 5인덱스는 없음 MAX를 나누어 0에 위치 시키기 위해서 나머지 숫자들은 5보다 작으니 본래 위치라고 생각하면됨!
	return q->data[save];
}

// 덱의 앞의 값을 확인만 하는 함수
int get_front(QueueType* q) {
	if (is_empty(q)) {
		printf(" 덱이 공백상태입니다");
		exit(1);
	}
	return q->data[(q->front+1)%MAX_QUEUE_SIZE]; // front인덱스에는 아무값도 없음 그러므로 front + 1을 진행
	// 나누기 MAX는 왜하지? -> front가 MAX - 1인 경우에 그냥 + 1을 하면 정해둔 배열을 넘어가버려서
}

// 덱의 뒤의 값을 확인만 하는 함수
int get_rear(QueueType* q) {
	if (is_empty(q)) {
		printf(" 덱이 공백상태입니다");
		exit(1);
	}
	return q->data[q->rear];
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
	QueueType d1;
	int element;

	init_queue(&d1);

	add_rear(&d1, 2);
	add_rear(&d1, 9);
	add_rear(&d1, 3);
	add_rear(&d1, 5);
	queue_print(&d1);

	element = delete_front(&d1);
	printf("거낸 정수 : %d\n", element);
	element = delete_front(&d1);
	printf("거낸 정수 : %d\n", element);
	queue_print(&d1);

	add_rear(&d1, 7);
	add_rear(&d1, 8);
	queue_print(&d1);

	element = delete_front(&d1);
	printf("거낸 정수 : %d\n", element);
	element = delete_front(&d1);
	printf("거낸 정수 : %d\n", element);
	queue_print(&d1);

	add_rear(&d1, 1);
	queue_print(&d1);
	
	printf("----------------------------------\n");
	QueueType d2;
	init_queue(&d2);

	add_front(&d2, 2);
	add_front(&d2, 9);
	add_front(&d2, 3);
	add_front(&d2, 5);
	queue_print(&d2);

	element = delete_rear(&d2);
	printf("거낸 정수 : %d\n", element);
	element = delete_rear(&d2);
	printf("거낸 정수 : %d\n", element);
	queue_print(&d2);

	add_front(&d2, 7);
	add_front(&d2, 8);
	queue_print(&d2);

	element = delete_rear(&d2);
	printf("거낸 정수 : %d\n", element);
	element = delete_rear(&d2);
	printf("거낸 정수 : %d\n", element);
	queue_print(&d2);

	add_front(&d2, 1);
	queue_print(&d2);

	return 0;
}