#include <stdio.h>
#include <stdlib.h>

// 문제 3) 두개의 노드를 연결하기

typedef struct Node
{
	int data;
	struct Node* next;
} Node;

int main(void) {
	Node* ptr = (Node*)malloc(sizeof(Node) * 2);
	if (ptr == NULL) {
		printf("메모리가 할당되지 않았습니다.\n");
		return 1;
	}

	for (int i = 0; i < 2; i++)
	{
		(ptr + i)->data = 10 * (i + 1);
	}

	ptr->next = ptr + 1; // 첫 번째 노드의 next가 두 번째 노드를 가리키도록 연결!
	(ptr + 1)->next = NULL; // 두 번째 노드의 next를 NULL로 설정!

	printf("첫 번째 노드의 데이터 출력: %d\n", ptr->data);
	printf("첫 번째 노드의 next를 이용하여 두 번째 노드의 데이터 출력: %d", ptr->next->data);
	free(ptr);
	return 0;
}