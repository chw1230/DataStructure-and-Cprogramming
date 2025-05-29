/*트리 속 노드의 개수, 높이 구하기*/

#include <stdio.h>	
#include <stdlib.h>
#define MAX(a,b) ((a) > (b) ? (a) : (b))

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

// 노드의 개수 구하는 함수
int getNodeCount(TreeNode* root) {
	int cnt = 0;
	if (root != NULL) {
		cnt = 1 + getNodeCount(root->left) + getNodeCount(root->right);
		// root 가 NULL이 아닌 경우에만 1을 더하도록 해서  노드의 개수를 계산
	}
	return cnt;
}

// leaf 노드의 개수 구하는 함수
int getLeafNodeCount(TreeNode* root) {
	int cnt = 0;
	if (root != NULL) { 
		if (root->left == NULL && root->right == NULL) {
			return 1; // 자식 노드가 모두 NULL이면 leaf 노드 이기 때문에 1을 반환
		}
		else {
			cnt = getLeafNodeCount(root->left) + getLeafNodeCount(root->right);
		}
	}
	// root 가 NULL 이면 0을 반환
	return cnt;	
}

// Non leaf 노드의 개수 구하는 함수
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

// 트리의 높이를 구하는 함수
int getHeight(TreeNode* root) {
	int height = 0;
	if (root != NULL) {
		height = 1 + MAX(getHeight(root->left), getHeight(root->right));
	}
	return height;
}

int main(void) {
	printf("노드의 개수 구하기 = %d\n", getNodeCount(root)); 
	printf("Leaf 노드의 개수 구하기 = %d\n", getLeafNodeCount(root));
	printf("Non Leaf 노드의 개수 구하기 = %d\n", getNonLeafNodeCount(root));
	printf("Tree의 높이 구하기 = %d\n", getHeight(root));
	return 0;
}
