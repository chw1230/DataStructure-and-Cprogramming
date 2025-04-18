#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct ListNode {
	element data;
	struct ListNode* link;
} ListNode;
 
// 원형 연결 리스트의 처음에 삽입
ListNode* insert_first(ListNode* head, element data)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	if (head == NULL) { // 리스트가 하나도 없는 경우
		head = node; 
		node->link = head; // node의 링크가 자기 자신을 가리키도록
	}
	else {
		node->link = head->link; // 새로 만든 노드가 기존의 head의 다음 노드를 가리키도록하기
		head->link = node; // 현재 head가 새로생긴 노드를 가리키도록 바꾸기
		
	}
	return head; //변경된 헤드 포인터를 반환한다.
}

// 원형 연결 리스트의 끝에 삽입
ListNode* insert_last(ListNode* head, element data)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	if (head == NULL) { // 리스트가 하나도 없는 경우
		head = node;
		node->link = head; // node의 링크가 자기 자신을 가리키도록
	}
	else {
		node->link = head->link; // 새로 만든 노드가 기존의 head의 다음 노드를 가리키도록하기
		head->link = node; // 현재 head가 새로생긴 노드를 가리키도록 바꾸기
		head = node; // 마지막으로 추가된 노드를 헤드 노드로 바꾸기
	}
	return head; //변경된 헤드 포인터를 반환한다.
}

// 리스트의 항목 출력
void print_list(ListNode* head){

	ListNode* p;

	if (head == NULL) {
		return;
	}
	p = head->link; // 헤드 노드가 마지막 노드를 가리키도록 구성하였기 때문에 p를 head -> link 를 주기
	do {
		printf(" %d ", p->data);
		if (p != head) { // '->' 나오게하는 조건 추가하기! 맨 마지막에는 나오지 않게 하도록!
 			printf("->");
		}
		p = p->link;
	} while (p != head->link); // 처음에 시작한 주소로 다시 돌아오면 끝내기
}



// 테스트 프로그램
int main(void) {
	ListNode* head = NULL;

	head = insert_last(head, 20);
	head = insert_last(head, 30);
	head = insert_last(head, 40);
	head = insert_first(head, 10);
	print_list(head);
	return 0;
}