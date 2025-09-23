#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int n, m; // 노드의 수, 간선의 수
vector<int> graph[10001]; // 정방향 그래프
vector<int> Rgraph[10001]; // 역방향 그래프
bool visited[10001]; // 방문 배열
int pre[10001], post[10001]; // pre - dfs 시작할 때의 cnt, post - dfs 끝날 때의 cnt
int cnt; // pre, post 구하기 위한 cnt
int ccFlag; // SCC 개수를 카운트하는 변수
int cc[10001]; // idx에 해당하는 노드들이 어떤 cc에 속하는지 표시하는 배열

void dfs_R(int v) { // 역방향 그래프의 dfs
	visited[v] = true;
	pre[v] = cnt++;
	for (int i = 0; i < Rgraph[v].size(); i++) {
		if (!visited[Rgraph[v][i]]) { // 방문하지 않았다면
			dfs_R(Rgraph[v][i]);
		}
	}
	post[v] = cnt++;
}

int getMaxPost() { // post가 가장 큰 노드의 번호 반환하는 함수
	int max = -1;
	int idx = -1; // 가장 큰 post 값을 가지는 노드의 번호
	for (int i = 1; i <= n; i++) {
		if (!visited[i] && post[i] > max) { // 방문하지 않았고, post가 가장 크다면
			max = post[i]; // 가장 큰 값 최신화
			idx = i; // 노드 번호 최신화
		}
	}
	return idx;
}

void dfs(int v) { // 정방향 그래프의 dfs
	visited[v] = true;
	cc[v] = ccFlag; // 현재 ccFlag로 표시하기
	for (int i = 0; i < graph[v].size(); i++) {
		if (!visited[graph[v][i]]) { // 방문하지 않았다면
			dfs(graph[v][i]); // 연결되어 있는 노드로 dfs 수행하며 같은 ccFlag로 표기하기
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b); // 정방향 그래프
		Rgraph[b].push_back(a); // 역방향 그래프
	}

	// 오름차순 정렬
	for (int i = 1; i <= n; i++) {
		sort(graph[i].begin(), graph[i].end());
		sort(Rgraph[i].begin(), Rgraph[i].end());
	}

	cnt = 1;
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			dfs_R(i);
		}
	}


	cout << "\nSCC 출력\n";

	// visited 배열 초기화
	fill(visited, visited + n + 1, false);
	ccFlag = 1; // 만약 하나의 cycle이 있다면, 그것은 하나의 scc이므로 1부터 시작하기
	// post의 내림차순을 통해서 정방향 그래프에서 dfs 수행하기
	for (int i = 1; i <= n; i++) {
		int maxPost = getMaxPost(); // 가장 큰 post 값을 가지는 노드 번호 반환하기
		if (maxPost == -1) {
			break; // 모든 노드를 방문했다면 종료하기
		}
		dfs(maxPost); // 정방향 그래프에서 dfs 수행하기

		for (int j = 1; j <= n; j++) { // cc 배열에 현재 ccFlag로 표시하기
			if (cc[j] == ccFlag) {
				cout << j << " ";
			}
		}

		cout << "\n";
		ccFlag++;
	}
}
/* 
scc 알고리즘 : 주어진 그래프의 vertex들을 strongly connected(= 양방향 모두 도달 가능)된 vertex들의 집합으로 분할 
방향 그래프에서 어떤 두 정점 u, v에 대해 u→v, v→u 경로가 모두 존재한다면, u와 v는 같은 SCC에 속한다!

scc 알고리즘 전략 : sink(= 나가는 간선(out degree = 0) strongly connected component를 찾아서 제거!
역방향 그래프에서 dfs 수행해서 pre, post 구하기 , 구한 post를 가지고 정방향 그래프에서 post 내림차순 dfs 수행하기!
수행하면서 ccFlag(= scc 개수)로 표시하기!
*/