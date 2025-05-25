#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50
/* vertices = node = 정점 / edge = 간선 */

typedef struct GraphNode {
	int node; // 노드가 들어가는 변수 
	struct GraphNode* link; // 다른 노드를 가리킬 포인터 변수
}GraphNode;

typedef struct GraphType {
	int nodeCnt; // 노드의 개수를 저장할 변수
	GraphNode* adj_list[MAX_VERTICES];
}GraphType;

// 그래프 초기화 함수
void init(GraphType* g) {
	g->nodeCnt = 0; // 노드의 개수 0으로 설정
	for (int i = 0; i < MAX_VERTICES; i++) { // 노드의 최대개수 만큼 반복
		g->adj_list[i] = NULL; // 모두 null을 가리키도록 초기화
	}
}

// 노드 삽입 함수
void insert_node(GraphType* g, int v) {
	if (((g->nodeCnt) + 1) > MAX_VERTICES) {
		printf("노드의 개수를 초과 하였음");
		return;
	}
	(g->nodeCnt)++; // 노드의 개수 올리기
}

// 엣지 삽입 함수
void insert_edge(GraphType* g, int u, int v) { // u->v , u와 v를 연결하는 엣지 
	if (u >= g->nodeCnt || v >= g->nodeCnt) {
		printf("노드 번호 오류");
		return;
	}

	GraphNode* newNode = (GraphNode*)malloc(sizeof(GraphNode));
	newNode->node = v;
	newNode->link = g->adj_list[u];
	g->adj_list[u] = newNode; // 새로 추가한 노드가 가장 좌측에 위치한 형태 (임의로 선택 한 것)
}

// 출력 함수
void print_adj_list(GraphType* g) {
	for (int i = 0; i < g->nodeCnt; i++) {
		GraphNode* p = g->adj_list[i];

		printf("정점 %d의 인접 리스트", i);

		while (p != NULL) {
			printf("-> %d", p->node);
			p = p->link;
		}
		printf("\n");
	}
}

int main(void) {
	GraphType* g = (GraphType*)malloc(sizeof(GraphType));
	init(g);

	for (int i = 0; i < 4; i++) {
		insert_node(g, i);
	}

	insert_edge(g, 0, 1);
	insert_edge(g, 1, 0);
	insert_edge(g, 0, 2);
	insert_edge(g, 2, 0);
	insert_edge(g, 0, 3);
	insert_edge(g, 3, 0);
	insert_edge(g, 1, 2);
	insert_edge(g, 2, 1);
	insert_edge(g, 2, 3);
	insert_edge(g, 3, 2);
	print_adj_list(g);

	free(g);
	return 0;
}