#include <stdio.h>
#include <stdlib.h>
/*
 단순연결 리스트가 정렬되지 않은 정수들의 리스트를 저장
 리스트에서 최대값과 최소값을 찾는 프로그램 작성
*/
typedef int element;

typedef struct ListNode {
	element data;
	struct ListNode* link;
} ListNode;

// 리스트의 시작 부분에 항목을 삽입하는 함수
ListNode* insert_first(ListNode* head, int value) {

	ListNode* p = (ListNode*)malloc(sizeof(ListNode));

	p->data = value; // p에 값을 넣어주기

	// 여기 순서가 중요해!!
	p->link = head; // p의 link가 head가 가리키는 노드를 가리키도록 하기!
	head = p; // head가 p가 가리키는 노드를 가리키도록 하기
	return head;
	// p는 그냥 놔둬도 사라짐 지역변수이니까
}


// 리스트를 방문하여 모든 항목을 출력하는 함수
void print_list(ListNode* head) {
	/* for 문의 사용
	for (ListNode* p = head; p != NULL; p = p->link) {
		printf("%d ->", p->data);
	}
	*/

	// while 문 사용
	ListNode* p = head;
	while (p != NULL) {
		printf("%d -> ", p->data);
		p = p->link;
	}
	printf("NULL\n");
}

// 연결 리스트에서 최소값과 최댓값을 찾는 함수
void MinMaxfromList(ListNode* head) {
	ListNode* p = head;
	int max = head->data;
	int min = head->data;
	while (p != NULL) {
		if (max < p->data) {
			max = p->data;
		}
		else if (min > p->data) {
			min = p->data;
		}
		p = p->link;
	}
	printf("MAX = %d 이고, min = %d 이다.", max, min);
}


// 테스트 프로그램
int main(void)
{
	ListNode* head = NULL;
	head = insert_first(head, 10);
	head = insert_first(head, 13);
	head = insert_first(head, 8);
	head = insert_first(head, 33);
	head = insert_first(head, 21);
	print_list(head);
	MinMaxfromList(head);
	return 0;
}