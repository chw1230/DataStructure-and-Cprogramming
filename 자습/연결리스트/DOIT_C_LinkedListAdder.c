#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node * next;
} Node;

void AddNum(Node **head, Node **tail, int data) {
	if (*head != NULL) {  // head가 참조하는 경우
		(*tail) -> next = (Node*)malloc(sizeof(Node)); // 메모리 할당
		*tail = (*tail)->next; // 마지막 노드 최신화
	}
	else { // head가 아무 것도 참조 하지 않는 경우
		*head = (Node*)malloc(sizeof(Node)); 
		*tail = *head; // 마지막 노드 최신화
	}
	(*tail)->data = data; // 마지막 노드에서 data 접근
	(*tail)->next = NULL; // 마지막 노드의 next를 NULL로 설정하며 마지막임을 명확히!
}


void main(void) {
	Node* head = NULL; // 헤드 포인터 첫번째 노드를 가리킴
	Node* tail = NULL;
	Node* p;
	int data;
	int sum = 0;

	/*
	* Node를 채우는 반복문
	*/
	while (1) {
		printf("숫자를 입력하시오(-1 입력->종료): ");
		scanf("%d", &data);
		if (data == -1) break;

		AddNum(&head, &tail, data);
	}

	/*
	* Node의 data를 출력하고, sum에 저장하는 반복문
	*/
	p = head;
	while (p != NULL) {
		if (p != head) { // 처음에 head와 주소가 같을때 '+' 출력 x
			printf("+");
		}
		printf(" %d ", p->data);
		sum += p->data;
		p = p->next;
	}
	printf(" = %d", sum);

	/*
	*  Node의 할당을 해제하는 반복문
	*/
	while (head != NULL) {
		p = head;
		head = head->next;  // head에 다음 노드로 넘어갈 주소 저장해두기!
		free(p);
	}
	tail = head; // head가 NULL이 됨!, tail에도 NULL 저장
}
