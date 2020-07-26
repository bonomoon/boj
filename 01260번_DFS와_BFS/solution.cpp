#include <cstdio>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>

std::vector<int> graph[1001];

void makeGraph(int N, int M) {
	int x, y;

	for(int i = 0; i < M; ++i) {
		scanf("%d %d", &x, &y);
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	for (int i = 1; i < N; ++i) {
		std::sort(graph[i].begin(), graph[i].end());
	}
}

void dfs(int V, int N) {
	bool visited[1001] = { 0, };
	std::stack<int> s;

	s.push(V);
    visited[V] = true;
	printf("%d ", V);

    while (!s.empty()) {
		int v = s.top();

		s.pop();

		for(int i = 0; i < graph[v].size(); ++i) {
			if(graph[v][i] && !visited[graph[v][i]]) {
				printf("%d ", graph[v][i]);
				visited[graph[v][i]] = true;
                s.push(v);
                s.push(graph[v][i]);
                break;
            }
		}
    }
}

void bfs(int V, int N) {
	bool visited[1001] = { 0, };
	std::queue<int> q;

	q.push(V);
    visited[V] = true;
	
	while(!q.empty()) {
		int v = q.front();

		q.pop();

		for(int i = 0; i < graph[v].size(); ++i) {
			if(graph[v][i] && !visited[graph[v][i]]) {
				visited[graph[v][i]] = true;
				q.push(graph[v][i]);
			}
		}

		printf("%d ", v);
	}
}

int main() {
	int N, M, V; // N: 정점의 개수, M: 간선의 개수 V: 탐색 시작 정점의 번호 
	scanf("%d %d %d", &N, &M, &V);

	makeGraph(N, M);
	dfs(V, N);
	printf("\n");
	bfs(V, N);

	return 0;
}