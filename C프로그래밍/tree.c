#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct tn {
	char *w; 
	struct tn *l; // 좌측
	struct tn *r; // 우측
} TreeNode;

// 추가하는 함수 
TreeNode *add(TreeNode *p, char *w)
{
	if (p == NULL) { // null 인 경우 노드 새로 만들기
		p = (struct tn *)malloc(sizeof(TreeNode));
		p->w = w;
		p->l = p->r = NULL;
	}
	else if (strcmp(w, p->w) < 0) // 사전 순으로 더 작은 경우에 좌측에 추가하기
		p->l = add(p->l, w);
	else
		p->r = add(p->r, w); // 사전 순으로 더 큰 경우이기에 우측에 추가하기
	return p;
}

void preorder(TreeNode *p) // 전위 순회로 트리 출력하기
{
	if (p != NULL) {
		printf("%s\n", p->w);
		preorder(p->l);
		preorder(p->r);
	}
}

void inorder(TreeNode *p){ // 중위 순회로 트리 출력하기
	if (p != NULL){
		inorder(p->l);
		printf("%s\n",p->w);
		inorder(p->r);
	}
}

void postorder(TreeNode *p){ // 후위 순회로 트리 출력하기
	if (p != NULL){
		postorder(p->l);
		postorder(p->r);
		printf("%s\n",p->w);
	}
}

int main(void)
{	
	// char 타입을 중심으로 저장하기에 2023이 아오면 2와 알파벳을 비교 / 2는 50(아스키), a는 97(아스키)
	char *str[] = {"have", "a", "very", "good", "2023", "summer", "vacation"};
	struct tn *r;
	r = NULL;

	int num = (int)(sizeof(str) / sizeof(char *));

	for (int i = 0; i < num; i++) // for 루프 돌면서 추가
		r = add(r, str[i]);
	preorder(r); // 출력
	printf("\n");
	inorder(r);
	printf("\n");
	postorder(r);

	return 0;
}

