#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct DistNode {
	element data;
	struct DistNode* llink; // 좌측
	struct DistNode* rlink; // 우측
} DistNode;

// 이중 연결 리스트 초기화
void init(DistNode* phead) {
	phead->llink = phead;
	phead->rlink = phead;
}

// 새로운 데이터를 노드 before의 오른쪽에 삽입
void dinsert(DistNode* before, element data) {
	DistNode* newnode = (DistNode*)malloc(sizeof(DistNode));
	newnode->data = data;

	newnode -> rlink = before -> rlink;
	newnode->llink = before;

	before->rlink->llink = newnode;
	before->rlink = newnode;
}

// 노드 removed를 삭제
void ddelete(DistNode* head, DistNode* removed) {
	if (removed == head) return; // 삭제할 지스트 존재 x

	removed->llink->rlink = removed->rlink;
	removed->rlink->llink = removed->llink;

	free(removed);
}

// 이중 연결 리스트의 노드를 출력
void print_dlist(DistNode* phead) {
	DistNode* p;
	for (p = phead->rlink; p != phead; p = p->rlink) {
		printf("<-| | %d | |->", p->data);
	}
	printf("\n");
}

// 매개변수로 전달된 값의 탐색
DistNode* search(DistNode *head, element data) {
	DistNode* p;
	for (p = head->rlink; p != head; p = p->rlink) {
		if (p->data == data) {
			return p;
		}
	}
	return NULL;
}

// 매개변수로 전달된 값이 있는 노드 삭제
DistNode* ddelete_by_value(DistNode* head, element data) {
	DistNode* p;
	for (p = head->rlink; p != head; p = p->rlink) {
		if (p->data == data) {
			p->rlink->llink = p->llink;
			p->llink->rlink = p->rlink;
			free(p);
			return head;
		}
	}
	return NULL;
}

// 이중 연결 리스트 테스트 프로그램
int main(void) {
	printf("실습-1\n");
	DistNode* head = (DistNode*)malloc(sizeof(DistNode));
	init(head);
	printf("추가 단계\n");
	for (int i = 0; i < 5; i++) {
		dinsert(head, i);
		print_dlist(head);
	}

	printf("\n삭제 단계\n");
	for (int i = 0; i < 5; i++) {
		print_dlist(head);
		ddelete(head, head->rlink);
	}
	free(head);

	printf("\n\n\n실습-2\n");
	DistNode* head2 = (DistNode*)malloc(sizeof(DistNode));
	init(head2);
	dinsert(head2, 1); 
	dinsert(head2, 2);
	dinsert(head2, 3); 
	dinsert(head2, 4);
	print_dlist(head2);

	element data;
	printf("탐색할 값: ");
	scanf("%d", &data);

	if (search(head2, data) != NULL)
		printf("%d 값이 리스트 안에 있습니다. \n ",data);
	else
		printf("%d 값이 리스트 안에 없습니다. \n ",data);

	printf("\n\n\n실습-3\n");
	printf("실습 2에서의 입력값을 삭제하기\n");
	if (head2 = ddelete_by_value(head2, data) != NULL) {
		print_dlist(head2); 
	}
	else {
		printf("존재하지 않는 값을 삭제하려고 하였습니다.");
	}
	return 0;
}
