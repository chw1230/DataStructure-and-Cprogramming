#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50
/* vertices = node = 정점 / edge = 간선 */

// 인접 행렬 그래프 표현
typedef struct GraphType {
	int nodeCnt; // 노드의 개수를 저장할 변수
	int adj_mtx[MAX_VERTICES][MAX_VERTICES];
}GraphType;

// 그래프 초기화 함수
void init(GraphType* g) {
	g->nodeCnt = 0; // 노드의 개수 0으로 설정
	for (int i = 0; i < MAX_VERTICES; i++) { // 노드의 최대개수 만큼 반복
		for (int j = 0; j < MAX_VERTICES; j++) {
			g->adj_mtx[i][j] = 0;
		}
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
void insert_edge(GraphType* g, int start, int end) {
	if (start >= g->nodeCnt || end >= g->nodeCnt) {
		printf("노드 번호 오류");
		return;
	}
	// 방향이 없는 그래프의 특징 고려
	g->adj_mtx[start][end] = 1; 
	g->adj_mtx[end][start] = 1; 
}

// 그래프 출력 함수
void print_adj_mtx(GraphType* g) {
	for (int i = 0; i < g->nodeCnt; i++) {
		for (int j = 0; j < g->nodeCnt; j++) {
			printf("%d ", g->adj_mtx[i][j]);
		}
		printf("\n");
	}
}

int main(void) {
	GraphType* g = (GraphType*)malloc(sizeof(GraphType));
	init(g); //초기화

	for (int i = 0; i < 4; i++) { // 노드의 개수 설정
		insert_node(g, i);
	}

	insert_edge(g, 0, 1);
	insert_edge(g, 0, 2);
	insert_edge(g, 0, 3);
	insert_edge(g, 1, 2);
	insert_edge(g, 2, 3);
	printf("인접 행렬 방식의 그래프 구현");
	print_adj_mtx(g);

	free(g);
}