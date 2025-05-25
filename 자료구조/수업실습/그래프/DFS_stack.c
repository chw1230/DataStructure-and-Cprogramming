#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50

typedef struct GraphNode {
    int node;
    struct GraphNode* link;
} GraphNode;

typedef struct GraphType {
    int nodeCnt;
    GraphNode* adj_list[MAX_VERTICES];
} GraphType;

// 방문 배열
int visited[MAX_VERTICES];

// 스택 자료구조
typedef struct Stack {
    int data[MAX_VERTICES];
    int top;
} Stack;

// 스택 관련 함수들
void init_stack(Stack* s) {
    s->top = -1;
}

int is_empty(Stack* s) {
    return s->top == -1;
}

void push(Stack* s, int item) {
    s->data[++(s->top)] = item;
}

int pop(Stack* s) {
    return s->data[(s->top)--];
}

int peek(Stack* s) {
    return s->data[s->top];
}

// 그래프 초기화
void init(GraphType* g) {
    g->nodeCnt = 0;
    for (int i = 0; i < MAX_VERTICES; i++) {
        g->adj_list[i] = NULL;
    }
}

// 노드 삽입
void insert_node(GraphType* g, int v) {
    if (g->nodeCnt + 1 > MAX_VERTICES) {
        printf("노드 수 초과!\n");
        return;
    }
    g->nodeCnt++;
}

// 엣지 삽입
void insert_edge(GraphType* g, int u, int v) {
    GraphNode* newNode = (GraphNode*)malloc(sizeof(GraphNode));
    newNode->node = v;
    newNode->link = g->adj_list[u];
    g->adj_list[u] = newNode;
}

// 인접 리스트 출력
void print_adj_list(GraphType* g) {
    for (int i = 0; i < g->nodeCnt; i++) {
        GraphNode* p = g->adj_list[i];
        printf("정점 %d의 인접 리스트", i);
        while (p != NULL) {
            printf(" -> %d", p->node);
            p = p->link;
        }
        printf("\n");
    }
}

// 스택 기반 DFS
void dfs_stack(GraphType* g, int v) {
    Stack s;
    init_stack(&s);
    push(&s, v); // 시작 정점을 스택에 push

    while (!is_empty(&s)) { // 스택이 빌 때까지 반복
        int current = pop(&s); // 스택에서 정점 꺼내기
        if (!visited[current]) {
            visited[current] = 1; // 방문 처리
            printf("정점 %d -> ", current); // 정점 출력

            // 현재 정점에 인접한 모든 정점을 스택에 push
            // (인접 리스트이므로, 뒤에 삽입된 정점이 먼저 탐색됨 → DFS 순서 보장)
            GraphNode* w = g->adj_list[current];
            while (w != NULL) {
                if (!visited[w->node]) {
                    push(&s, w->node); // 방문하지 않은 정점만 push
                }
                w = w->link; // 다음 인접 정점으로 이동
            }
        }
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

    printf("깊이 우선 탐색_스택\n");
    dfs_stack(g, 0);
    free(g);
    return 0;
}