#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

vector<vector<int>> graph; // 인접 리스트
vector<int> visited;       // 방문 상태 : 0 -> 미방문, 1 -> 방문중, 2 -> 방문 완료
stack<int> S;              // 위상 정렬 결과 저장할 스택, 결과 스택에 있는거 pop하면서 출력하면 됨
bool isCycle = false;      // 사이클 존재 여부

// DFS 함수
void dfs(int u) {
	if (visited[u] == 1) { // 백엣지가 발견된 경우임! -> cycle 발생
		isCycle = true;
        return; 
	}
    if (visited[u] == 2) {
        return; // 이미 방문 완료된 vertex
    }

	// 여기까지 오면 방문한 적 없는 vertex
	visited[u] = 1; // 방문중 처리
    for (int v : graph[u]) {
            dfs(v);
    } // 연결된 것을 다 돌고 나면 
	S.push(u); 
    visited[u] = 2; // 방문 완료 처리 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; // 정점 수, 간선 수
    cin >> N >> M;

    graph.resize(N + 1);
    visited.resize(N + 1, 0);

    // 간선 입력하기
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }

    for (int i = 1; i <= N; i++) {
        // 정점의 인접 리스트를 오름차순으로 정렬 하기
        sort(graph[i].begin(), graph[i].end());
	}

    for ( int i = 1; i <= N; i++) {
        if (visited[i] == 0) {
            dfs(i);
        }
        if (isCycle) {
			break; // 사이클 발생했으면 더 이상 탐색할 필요가 없음
		}
	}
    
    if (isCycle) {
        cout << "사이클 발생!";
		return 0; // 사이클 발생했으니 종료
    }
	// 스택에 있는거 pop하면서 출력하기
	while (!S.empty()) {
		cout << S.top() << " ";
		S.pop();
	}

    return 0;
}
/*
6 6
2 1
2 4
1 3
4 3
3 6
3 5
결과 : 2 4 1 3 6 5

6 6
2 1
2 4
1 3
4 3
3 6
6 4
결과 : 사이클 발생!

3 3
1 2
2 3
3 1
결과 : 사이클 발생!

6 5
1 2
1 3
4 5
4 6
2 5
결과 : 4 6 1 3 2 5
*/