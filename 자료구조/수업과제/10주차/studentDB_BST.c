#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TreeNode {
	long id;
	char name[20];
	struct TreeNode* left, * right;
}TreeNode;

// 새로운 노드할당
TreeNode* new_node(long id, char* name) {
	TreeNode* tmp = (TreeNode*)malloc(sizeof(TreeNode));
	tmp->id = id;
	strcpy(tmp->name, name); // name에서 입력받은 결과의 주소를 통해 복제
	tmp->left = tmp->right = NULL;

	return tmp;
}


// 학생 정보 추가
TreeNode* insert_node(TreeNode* node, long id, char* name) {
	if (node == NULL) {
		return new_node(id, name);
	}

	if (id < node->id) {
		node->left = insert_node(node->left, id, name);
	}
	else if (id > node->id) {
		node->right = insert_node(node->right, id, name);
	}
	else {
		printf("이미 존재하는 학번, 추가 불가능\n");
	}
	return node;
}

// 중위 순회
void inorder(TreeNode* root) {
	if (root) {
		inorder(root->left);
		printf("학번: %ld, 이름: %s\n", root->id, root->name);
		inorder(root->right);
	}
}

// 특정 id를 가진 노드 찾기
TreeNode* search_node(TreeNode* node, long id) {
	while (node) {
		if (id < node->id) {
			node = node->left;
		}
		else if (id > node->id) {
			node = node->right;
		}
		else {
			return node;
		}
	}
	return NULL;
}

// 트리에서 가장 작은 id를 가진 노드를 찾는 함수
TreeNode* min_value_node(TreeNode* node) {
	TreeNode* current = node;
	while (current->left != NULL) {
		current = current->left;
	}
	return current;
}

// 학생 정보 삭제
TreeNode* delete_node(TreeNode* root, long id) {
	if (root == NULL) {
		printf("삭제할 학번이 존재하지 않음\n");
		return NULL;
	}

	if (id < root->id) {
		root->left = delete_node(root->left, id);
	}
	else if (id > root->id) {
		root->right = delete_node(root->right, id);
	}
	else {
		// 1. 자식이 없는 경우 (단말 노드)
		if (root->left == NULL && root->right == NULL) {
			free(root);
			return NULL;
		}
		// 2. 왼쪽 자식이 없는 경우 → 오른쪽 자식 노드로 대체
		else if (root->left == NULL) {
			TreeNode* tmp = root->right;
			free(root);
			return tmp;
		}
		// 3. 오른쪽 자식이 없는 경우 → 왼쪽 자식 노드로 대체
		else if (root->right == NULL) {
			TreeNode* tmp = root->left;
			free(root);
			return tmp;
		}

		// 4. 양쪽 자식이 모두 있는 경우
		// 오른쪽 서브트리에서 가장 작은 값을 가지는 노드를 찾아 현재 노드를 대체
		TreeNode* tmp = min_value_node(root->right);

		// 현재 노드의 데이터를 후계 노드의 값으로 덮어쓰기 (삭제 아님!)
		root->id = tmp->id;
		strcpy(root->name, tmp->name); // name도! 덮어쓰기
		root->right = delete_node(root->right, tmp->id); // 후계 노드를 실제로 삭제

	}
	return root;
}

int main() {
	TreeNode* root = NULL;

	while (1) {
		printf("\n=== 학생 정보 시스템 ===\n");
		printf("(1) 학생 정보 추가\n");
		printf("(2) 학생 정보 탐색\n");
		printf("(3) 학생 정보 삭제\n");
		printf("(4) 학생 정보 전체 출력\n");
		printf("(0) 종료\n");
		printf("선택: ");
		int n;
		scanf("%d", &n);

		if (n == 0) {
			printf("프로그램이 종료되었습니다.\n");
			return 0;

		}
		else if (n == 1) {
			char name[20];
			long id;

			printf("학번 입력: ");
			scanf("%ld", &id);
			printf("이름 입력: ");
			scanf("%s", name);

			root = insert_node(root, id, name);

		}
		else if (n == 2) {
			printf("=== 학생 정보 탐색 ===\n");
			long id;
			printf("찾을 학생의 학번 입력: ");
			scanf("%ld", &id);
			TreeNode* result = search_node(root, id);

			if (result) {
				printf("검색 결과 | 학번: %ld, 이름: %s\n", id, result->name);
			}
			else {
				printf("해당 학번 존재하지 않음\n");
			}
		}
		else if (n == 3) {
			printf("=== 학생 정보 삭제 ===\n");
			long id;
			printf("삭제할 학생의 학번 입력: ");
			scanf("%ld", &id);
			root = delete_node(root, id);
			printf("작업 완료\n");

		}
		else if (n == 4) {
			printf("=== 학생 정보 전체 출력 (오름차순) ===\n");
			inorder(root);
		}
		else {
			printf("잘못된 입력입니다.\n");
		}
	}
}
