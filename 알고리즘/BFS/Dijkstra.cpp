// 202210986 최현우 알고리즘 과제 PE03 Dijkstra + 경로 추적(추가로 해보기)
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

int N, M; // 노드 수, 엣지 수
vector<pair<int, int>> graph[10001]; // 인접 리스트 (가중치, 노드) -> 저장 형식 중요!!
int visited[10001]; // 방문 배열
int dist[10001]; // 최단 거리 배열
int pre[10001]; // 이전 노드 배열 ( 경로 추적용, 누굴 통해서 오는지! )

// 다익스트라 알고리즘 메서드
void dijkstra(int start) {
	priority_queue <pair<int, int>> pq; // 가중치를 통한 누적거리, 노드
	// 초기화 과정
	for (int i = 1; i <= N; i++)
	{
		dist[i] = (int)1e8; // 무한대로 초기화, 왜 큰 수로 초기화를 하는가? -> 최단 거리를 담기 위해서!
		pre[i] = -1; // 이전 노드
		visited[i] = 0; // 방문 배열
	}
	dist[start] = 0; // 시작 노드의 최단 거리는 0

	for (int i = 1; i <= N; i++)
	{
		pq.push(make_pair(-dist[i], i)); // 왜 -를 붙여서 넣는 거지? C++은 기본적으로 Max Heap 이기 때문에 큰 값이 먼저 나옴 하지만 우리는 오름차순으로 실행할 것이니까 '-' 붙여주기
	}

	while (!pq.empty()) {
		int cur = pq.top().second; // 현재 노드 / .second 는 뭐임? 우리가 pair할때 (가중치, 노드) 이렇게 했으니까 두번째 값이 노드임!!
		pq.pop();
		if (visited[cur] == 1) {
			continue; // 이미 방문한 노드면 넘어가기
		}
		visited[cur] = 1; // 방문 처리

		// 연결되어 있는 것들 중
		for(int i = 0; i < graph[cur].size(); i++)
		{
			int next = graph[cur][i].second; // cur 노드와 연결된 i번째 노드

			if (visited[next] == 1) {
				continue; // 이미 방문한 노드면 넘어가기
			}

			// edge relaxation!!
			int weight = graph[cur][i].first; // 연결된 노드의 가중치
			if (dist[next] > dist[cur] + weight) { // 기존 값이 더 크다면
				dist[next] = dist[cur] + weight; // 최단 거리 최신화
				pre[next] = cur; // 이전 노드 최신화
				pq.push(make_pair(-dist[next], next)); // 우선순위 큐에 넣기
			}

		}
	}
}

// 경로 추적 메서드
vector<int> build_path(int start, int target) {
	vector<int> path;
	// target부터 pre를 따라가면서 start까지 거슬러 올라가기!!
	for (int v = target; v != -1; v = pre[v]) {
		path.push_back(v);
		if (v == start) {
			break; // 시작 노드까지 오면 중단
		}
	}

	// start에 도달 못했으면 경로 없는 것!
	if (path.back() != start) {
		return {};
	}

	reverse(path.begin(), path.end()); // 뒤집어서 start → target 순서로 바꾸기
	return path;
}

int main()
{
	cin >> N >> M;
	
	for (int i = 0; i < M; i++)
	{
		int a, c, weight;
		cin >> a >> c >> weight;
		graph[a].push_back(make_pair(weight,c));
	}

	for (int i = 1; i <= N; i++)
	{
		sort(graph[i].begin(), graph[i].end()); // 정렬하기~
	}

	dijkstra(1); // 1번 노드에서 시작하기

	cout << "\n출력 :\n";
	for (int i = 1; i <= N; i++)
	{
		cout << "1번 노드에서 " << i << "번 노드까지의 최단 거리: " << dist[i] << "\n";

		vector<int> path = build_path(1, i); // 우리가 시작을 1번부터 한다고 했을 때 각 노드까지의 경로 추적하기
		if (path.empty()) {
			cout << "  경로 없음\n";
		} else {
			cout << "  경로: ";
			for (int j = 0; j < (int)path.size(); j++) {
				if (j != 0) {
					cout << " -> ";
				} 
				cout << path[j];
			}
			cout << "\n\n";
		}
	}
}

/*
6 11
1 2 50
1 3 45
1 4 10
2 3 10
2 4 15
3 5 30
4 1 20
4 5 15
5 2 20
5 3 15
5 6 3

출력 :
1번 노드에서 1번 노드까지의 최단 거리: 0
  경로: 1

1번 노드에서 2번 노드까지의 최단 거리: 45
  경로: 1 -> 4 -> 5 -> 2

1번 노드에서 3번 노드까지의 최단 거리: 40
  경로: 1 -> 4 -> 5 -> 3

1번 노드에서 4번 노드까지의 최단 거리: 10
  경로: 1 -> 4

1번 노드에서 5번 노드까지의 최단 거리: 25
  경로: 1 -> 4 -> 5

1번 노드에서 6번 노드까지의 최단 거리: 28
  경로: 1 -> 4 -> 5 -> 6
*/