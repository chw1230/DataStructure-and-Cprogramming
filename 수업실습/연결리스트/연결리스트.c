#include <stdio.h>
#include <stdlib.h>

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

// 리스트의 중간 부분에 항목을 삽입하는 함수
ListNode* insert(ListNode* head,ListNode*pre, int value) {

	ListNode* p = (ListNode*)malloc(sizeof(ListNode));

	p->data = value;

	// 순서 중요
	p->link = pre->link;
	pre->link = p;

	return head; // 헤드 부터 접근하도록 헤드를 반환해주는 것!
}

// 리스트의 첫 번째 항목을 삭제하는 함수
ListNode* delete_first(ListNode * head) {
	ListNode* removed;

	if (head == NULL) {
		return NULL;
	}

	removed = head; // 할당 해제를 위한 저장
	head = removed->link;
	free(removed);
	// 만약에 하나의 포인터로 표현해야 한다면 head = head -> link;
    return head;
}

// 리스트의 중간 항목을 삭제하는 함수
ListNode* delete_pre(ListNode* head, ListNode* pre)
{
	ListNode* removed; 
	removed = pre->link; 
	pre->link = removed->link; // 없앨 노드의 다음 노드를 가리키게 하기
	free(removed); 
	return head;
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

// 특정한 값을 탐색하는 함수
ListNode* search_list(ListNode* head, element x) {
	// 있으면 노드 없으면 null 반환

	ListNode* p = head;
	while (p != NULL) {
		if (p->data == x) {
			return p;
		}
		p = p->link;
	}
	return p;
}

// 2개의 리스트를 합하는 함수
ListNode* cooncat_linkedList(ListNode* head1, ListNode* head2) {
	// head1에 head2 연결하기

	// head1 이 null 이면 head2 반환
	if (head1 == NULL) {
		return head2;
	}
	else if (head2 == NULL) {
		return head1;
	}
	else {
		ListNode* p = head1;
		
		// head1의 끝을 찾기
		while (p->link != NULL) {
			p = p->link;
		}
		p->link = head2;
	}
	return head1;
}

int main(void) {
	ListNode* head = NULL;


	for (int i = 0; i < 5; i++) {
		head = insert_first(head, i*10);
		print_list(head);
	}

	/*head = insert_first(head, 500);
	print_list(head);*/

	int find = 500;
	if (search_list(head, find) != NULL)
		printf("리스트에서 %d을 찾았습니다.\n",find);
	else
		printf("리스트에서 %d을 찾지 못했습니다.\n",find);

	/*
	for (int i = 0; i < 5; i++) {
		head = delete_first(head);
		print_list(head);
	}
	*/


	ListNode* head2 = NULL;
	ListNode* combined_head = NULL;

	for (int i = 0; i < 3; i++) {
		head2 = insert_first(head2, i + 3);
	}
	print_list(head2);

	combined_head = cooncat_linkedList(head, head2);
	print_list(combined_head);

	return 0;
}

