#include <stdio.h>
#include <stdlib.h>
/*
단순연결 리스트에서 특정한 데이터값을 갖는 노드를 
삭제하는 함수를 작성
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


ListNode* delete_node(ListNode* head, int value) {
	ListNode* p = head; 
	ListNode* removed; // 삭제할 노드를 담을 포인터 변수


	if (p == NULL) {
		printf("노드가 비어있습니다.");
		return NULL;
	}


	// 찾는 값이 첫번째 노드에 있을 때, 아닐 때를 나누어서 생각하기

	// 첫 번째 노드에 찾는 값이 있을 때
	if (p->data == value) {
		head = p->link;
		free(p);
		return head;
	}

	// 아닌 경우
	while (p->link != NULL) {
		if (p->link->data == value) {
			removed = p->link; // 해제를 위한 저장
			p->link = p->link->link;
			free(removed);
			return head;
		}
		p = p->link;
	}

	if (p->link == NULL) {
		printf("찾는 값이 존재하지 않습니다.\n");
	}
	return head;
}

// 테스트 프로그램
int main(void)
{
	int value;
	ListNode* head = NULL;
	head = insert_first(head, 10);
	head = insert_first(head, 13);
	head = insert_first(head, 8);
	head = insert_first(head, 33);
	head = insert_first(head, 21);
	print_list(head);
	printf("삭제할 값을 입력하시오: ");
	scanf_s("%d", &value);
	head = delete_node(head, value);
	print_list(head);
	return 0;
}