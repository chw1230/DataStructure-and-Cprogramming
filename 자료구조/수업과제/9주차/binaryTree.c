#include <stdio.h>	
#include <stdlib.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
} TreeNode;

TreeNode n0 = { 0,NULL,NULL };
TreeNode n1 = { 1, NULL, &n0 };
TreeNode n2 = { 4, &n1, NULL };
TreeNode n3 = { 16, NULL, NULL };
TreeNode n7 = { 3, NULL, NULL };
TreeNode n8 = { 100, NULL, NULL };
TreeNode n4 = { 25, &n8, &n7 };
TreeNode n5 = { 20, &n3, &n4 };
TreeNode n6 = { 15, &n2, &n5 };
TreeNode* root = &n6;

// Non leaf 노드의 개수 구하는 함수(비단말 노드 개수 count)
int getNonLeafNodeCount(TreeNode* root) {
	int cnt = 0;
	if (root != NULL) {
		if (root->left != NULL || root->right != NULL) {
			// 자식 노드가 1개 이상 있으면 리프 노드가 아니기 때문에 이와 같이 조건을 설정
			cnt = 1 + getNonLeafNodeCount(root->left) + getNonLeafNodeCount(root->right);
		}
		else {
			return 0;
		}
	}
	return cnt;
}

//  값 검색하기
/* 이진 트리에서 특정 값을 갖는 노드를 재귀적으로 찾아 반환하는 함수
노드를 찾으면 해당 노드의 포인터를 반환, 없으면 NULL을 반환 */
TreeNode* search(TreeNode* node, int value) {
	if (node == NULL) {
		return NULL;
	}

	if (node->data == value) {
		return node; // 현재 노드에서 값 찾음
	}

	// 좌측에서 찾기
	TreeNode* p = search(node->left, value);
	if (p != NULL) { 
		// p가 NULL 이라면 좌측에 찾는 값이 없었던 것, 
		// NULL 아니면 (node->left)노드의 data와 value가 일치하는 것!
		return p;
	}

	// 우측에서 찾기
	return search(node->right, value);

	// 노드를 반환하는 경우는 오로지 data와 value가 같은 경우 밖에 없음
	// 나머지 경우에는 NULL을 반환
}

int main(void) {
	printf("Non Leaf 노드의 개수 구하기 = %d\n", getNonLeafNodeCount(root));

	int n;
	TreeNode* p;
	printf("찾을 값을 입력하시오: ");
	scanf("%d", &n);
	if ( (p = search(root, n)) != NULL) {
		printf("입력한 값 %d(이)가 트리에 존재합니다.\n", p->data);
	}
	else {
		printf("입력한 값이 트리에 존재하지 않습니다.");
	}
	return 0;
}