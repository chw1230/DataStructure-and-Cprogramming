//#include <stdio.h>	
//
//typedef struct TreeNode {
//	int data;
//	struct TreeNode* left, * right;
//} TreeNode;
////			+
////	  *			 +
//// 1      4  16      25
//TreeNode n1 = { 1, NULL, NULL };
//TreeNode n2 = { 4, NULL, NULL };
//TreeNode n3 = { '*', &n1, &n2 };
//TreeNode n4 = { 16, NULL, NULL };
//TreeNode n5 = { 25, NULL, NULL };
//TreeNode n6 = { '+', &n4, &n5 };
//TreeNode n7 = { '+', &n3, &n6 };
//TreeNode* exp = &n7;
//
//int evaluate(TreeNode* root) {
//	if (root == NULL) {
//		return 0;
//	}
//	if (root->left == NULL && root->right == NULL) { // 리프 노드들은 피연산자
//		return root->data; // 숫자 값 반환하기
//	} 
//	else {
//		int op1 = evaluate(root->left);
//		int op2 = evaluate(root->right);
//		printf("%d %c %d를 계산\n", op1, root->data, op2);
//		switch (root->data) {
//		case '+': return op1 + op2;
//		case '*': return op1 * op2;
//		case '-': return op1 - op2;
//		case '/': return op1 / op2;
//		}
//	}
//	return 0;
//}
//
//int main(void) {	
//	printf("수식의 값은 %d이다.\n", evaluate(exp));
//	return 0;
//}
