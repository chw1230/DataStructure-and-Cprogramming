#include <stdio.h>	

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

// pdf 41쪽

// 중위 순회
void inorder(TreeNode* root) {
	if (root) {
		inorder(root->left);
		printf("[%d] ", root->data);
		inorder(root->right);
	}
}

// 전위 순회
void preorder(TreeNode* root) {
	if (root){
		printf("[%d] ",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

// 후위 순회 
void postorder(TreeNode* root) {
	if (root) {
		postorder(root->left);
		postorder(root->right);
		printf("[%d] ", root->data);
	}
}

int main(void) {
	// 자손 보다 루트 먼저 방문
	printf("전위 순회="); // VLR V(root) -> L(left) -> R(right)
	preorder(root);
	printf("\n");

	// 왼쪽 자손, 루트, 우측 자손 순 방문
	printf("중위 순회="); // LVR L(left) -> V(root) -> R(right)
	inorder(root);
	printf("\n");
	
	// 루트 보다 자손 먼저 방문
	printf("후위 순회="); // LRVL(left) -> R(right) -> V(root)
	postorder(root);
	printf("\n");
	return 0;
}
