#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

vector<vector<int>> graph;
bool visited[1001];
stack<int> S;

// 탐색할 수 있는 노드가 있는지 확인하는 함수
bool can_explore(int u) {
	for (int w : graph[u]) {
		if (!visited[w]) {
			return true;
		}
	}
	return false;
}

// 다음에 방문할 수 있는 노드 찾는 함수
int next_cell(int u) {
	for (int w : graph[u]) {
		if (!visited[w]) {
			return w;
		}
	}
	return -1; 
}

// DFS - 재귀 호출 사용 -> stack
void dfs1(int v) {
	visited[v] = true; // 방문 처리
	cout << v << " "; // 시작 노드 출력

	for ( int i : graph[v]) { // v와 연결된 노드 루프 중 (range based for문)
		if (!visited[i]) { // 방문하지 않은 노드라면
			dfs1(i); // 재귀!
		}
	}
}

// DFS - 백트래킹 사용 -> stack
void dfs2(int s) {
	visited[s] = true;
	cout << s << " "; // 시작 노드 출력
	S.push(s);

	while (!S.empty()) {
		int u = S.top();      

		if (!can_explore(u)) { 
			S.pop();
			continue;
		}

		int v = next_cell(u);  // 아직 방문 안 한 이웃 하나
		visited[v] = true;     // push 직전에 방문 처리(중복 방지)
		cout << v << ' ';
		S.push(v);             // 내려간다. 부모 u는 스택에 남아 있음
	}
}

// DFS - 방문할 노드를 스택에 넣는 방법
void dfs3(int v) {
	S.push(v); // 시작 노드 스택에 넣기

	while (!S.empty()) { // 스택이 빌 때까지
		int cur = S.top(); // 스택의 top 노드 가져오기 / s.pop() 반환값 없음...
		S.pop(); // 스택에서 top 제거

		if (visited[cur]) {
			continue; // 이미 방문한 노드라면 넘어가기
		}

		visited[cur] = true; // 방문 처리
		cout << cur << " "; // 출력

		// stack에 push함을 고려해서 내림차순으로 루프를 돌기
		for (int i = (int)graph[cur].size() - 1; i >= 0; i--) {
			if (!visited[graph[cur][i]]) { // 방문하지 않은 노드라면
				S.push(graph[cur][i]); // 스택에 넣기
			}
		}
	}
}

int main()
{
	int V, E; // V: vertices 수, E: edges 수
	cin >> V >> E;

	graph.resize(V + 1); // 노드의 수 + 1) 만큼 초기화

	for (int i = 0; i < E; i++) {
		int u, v;
		cin >> u >> v; //  vertex1, vertex2 / 2개 입력 받기!

		// 방향 X -> 양쪽에 추가
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for (int i = 1; i <= V; i++) {
		sort(graph[i].begin(), graph[i].end()); // 오름차순으로 DFS하기 위해 정렬
	}

	cout << "\ndfs - 1번 시작 :\n";
	for (int i = 1; i <= V; i++) {
		if (visited[i]) {
			continue; // 방문한 노드라면 넘어가기
		}
		dfs1(i);
		cout << "\n";
	}

	cout << "\ndfs - 2번 시작 :\n";
	fill(visited, visited + V + 1, false); // (visited[0] 부터 , visited[V+1] 까지) 방문 배열 초기화 -> dfs - 2번 위해서
	for (int i = 1; i <= V; i++) {
		if (visited[i]) {
			continue; // 방문한 노드라면 넘어가기
		}
		dfs2(i);
		cout << "\n";
	}

	cout << "\ndfs - 3번 시작 :\n";
	while (!S.empty()) S.pop(); // 스택 초기화 -> dfs - 3번 위해서
	fill(visited, visited + V + 1, false); // (visited[0] 부터 , visited[V+1] 까지) 방문 배열 초기화 -> dfs - 3번 위해서
	for (int i = 1; i <= V; i++) {
		if (visited[i]) {
			continue; // 방문한 노드라면 넘어가기
		}
		dfs3(i);
		cout << "\n";
	}
	return 0;
}
/*
test1 :
48 115
9 44
44 48
16 48
16 24
6 24
6 31
31 41
13 41
13 29
9 20
44 20
44 19
48 19
48 11
16 11
16 33
24 33
24 43
6 43
6 2
31 2
31 47
41 47
41 40
13 40
13 5
5 29
19 20
19 11
11 33
33 43
2 43
2 47
40 47
5 47
20 18
20 34
19 34
19 39
11 39
1 11
1 33
33 36
43 36
43 14
2 14
2 45
47 45
47 21
21 40
38 40
5 38
5 26
18 34
34 39
1 39
1 36
14 36
14 45
21 45
21 38
26 38
18 8
8 34
34 37
37 39
39 10
1 10
1 17
17 36
15 36
14 15
3 14
3 45
28 21
45 28
21 30
30 38
22 38
22 26
8 37
10 37
10 17
15 17
3 15
3 28
30 28
22 30
8 25
4 8
4 37
35 37
10 35
10 23
23 17
17 32
15 32
7 15
3 7
3 46
28 46
28 42
30 42
30 12
12 22
22 27
4 25
4 35
23 35
23 32
7 32
7 46
42 46
12 42
12 27


tet2 :
1 0

test3 :
8 5
1 2
2 3
4 5
5 6
7 8

test4 :
5 10
1 2
1 3
1 4
1 5
2 3
2 4
2 5
3 4
3 5
4 5
*/
