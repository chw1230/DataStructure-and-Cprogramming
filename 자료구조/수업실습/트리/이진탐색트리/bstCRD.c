#include <stdio.h>	
#include <stdlib.h>

typedef struct TreeNode {
	int key;
	struct TreeNode* left, * right;
} TreeNode;

// 새로운 노드를 만드는 함수_이진 탐색 트리의 삽입에서 사용
TreeNode* new_node(int item) {
	TreeNode* tmp = (TreeNode*)malloc(sizeof(TreeNode));
	tmp->key = item;
	tmp->left = tmp->right = NULL; // 리프 노드로 생성되는 과정이기 때문에 좌우 NULL로!

	return tmp;
}

// 이진 탐색 트리에서의 삽입
TreeNode* insert_node(TreeNode* node, int key) {
	// 트리가 공백인 경우에 새로운 노드를 반환
	if (node == NULL) {
		return new_node(key);
	}

	if (key < node->key) { // key 값이 더 작은 경우 좌측에 추가
		node->left = insert_node(node->left, key);
	}
	else if (key > node->key) { // key 값이 더 큰 경우 우측에 추가
		node->right = insert_node(node->right, key);
	}

	return node; 
}

// 이진 탐색 트리에서의 탐색
TreeNode* search(TreeNode* node, int key) {
	/*
	// 순환을 이용한 탐색
	if ( node == NULL ){ // 찾는 값이 없는 경우
		return NULL;
	}

	if ( key == node -> key ){  // 찾는 값이 있을 때 노드 반환 
		return node;
	} 
	else if ( key < node -> key ) { // 찾는 값이 작은 경우 좌측 탐색
		return search( node -> left, key );
	}
	else { // 찾는 값이 큰 경우 우측 탐색
		return search( node -> right, key );
	}
	*/

	// 반복을 이용한 탐색
	while (node != NULL) {
		if (node->key == key) {
			return node;
		}
		else if (key < node->key) {
			node = node->left;
		}
		else
		{
			node = node->right;
		}
	}
	return NULL; // 루프를 돌고 나서 찾는 값이 없는 경우 NULL 반환
}

// 트리에서 가장 작은 값을 가지는 노드를 찾는 함수
TreeNode* min_value_node(TreeNode* node) {
	TreeNode* current = node;
	// 트리에서 가장 좌측의 노드로 쭉 내려감! (트리에서 가장 좌측 = 가장 작은 값)
	while (current->left != NULL) {
		current = current->left;
	}

	return current;
}

// 이진 탐색 트리에서의 삭제
TreeNode* delete_node(TreeNode* root, int key) {
	if (root == NULL) { // 삭제하려는 값을 가진 노드가 없는 경우
		return NULL;
	}

	// 찾으려는 값이 작은 경우 좌측 탐색
	if (key < root->key) {
		root->left = delete_node(root->left, key);
	}
	// 찾으려는 값이 큰 경우 우측 탐색
	else if (key > root->key) {
		root->right = delete_node(root->right, key);
	}
	// 찾으려는 값이랑 같은경우
	else {
		// 삭제하려는 노드가 리프 노드인 경우
		if (root->left == NULL && root->right == NULL) {
			free(root);
			return NULL;
		} 
		// 삭제하려는 노드가 한개의 서브 트리를 가진 경우(=삭제하려는 노드가 하나의 자식만 가지는 경우)
		else if(root -> left == NULL) { // 자식노드가 우측에만 존재하는 경우
			TreeNode* tmp = root->right;
			free(root);
			return tmp; // 노드의 자식을 가리키는 새로운 노드르 만들어 반환
		}
		else if(root -> right == NULL) { // 자식노드가 좌측에만 존재하는 경우
			TreeNode* tmp = root->left;
			free(root);
			return tmp; // 노드의 자식을 가리키는 새로운 노드르 만들어 반환
		}
		// 삭제하려는 노드가 두개의 서브 트리를 가진 경우(=삭제하려는 노드가 두개의 자식만 가지는 경우)
		TreeNode* tmp = min_value_node(root->right); // 삭제할 노드의 자리에 올 노드를 새로 만든 노드에 넘겨 주기 (어떤 것을 넘겨주지? - 좌측 서브 트리에서 가장 큰 값 혹은 우측 서브 트리에서 가장 작은 값(여기서는 이걸 선택)
		root->key = tmp->key; // 중위 순회시 대체할 노드를 복사
		root->right = delete_node(root->right, tmp->key); // 그냥 free를 사용하지 않는 이유 -> 삭제할 노드를 대체하는 노드의 사직 노드를 고려해야하기 때문에!
	}
	return root;
}

// 중위 순회
void inorder(TreeNode* root) {
	if (root) {
		inorder(root->left);
		printf("[%d] ", root->key);
		inorder(root->right);
	}
}

int main(void) {
	TreeNode* root = NULL;

	// 삽입 테스트
	int values[] = { 30, 20, 10, 40, 50, 60 };
	for (int i = 0; i < sizeof(values) / sizeof(int); i++) {
		root = insert_node(root, values[i]);
	}
	printf("=== 삽입 완료 ===\n\n");

	// 중위 순회
	printf("이진 탐색 트리 중위 순회 결과:\n");
	inorder(root);
	printf("\n");
	printf("=== 출력 완료 ===\n\n");


	// 탐색
	if (search(root, 30) != NULL)
		printf("탐색 성공: 30을 찾았습니다.\n");
	else
		printf("탐색 실패: 30이 없습니다.\n");

	printf("=== 탐색 완료 ===\n\n");


	// 삭제
	printf("삭제 테스트\n");
	root = delete_node(root, 30);
	printf("노드 30 삭제 완료.\n");
	printf("=== 삭제 완료 ===\n\n");


	// 삭제 후 중위 순회 (❗root로 순회해야 함)
	printf("삭제 후 이진 탐색 트리 중위 순회 결과:\n");
	inorder(root);
	printf("=== 재출력 완료 ===\n\n");


	return 0;
}