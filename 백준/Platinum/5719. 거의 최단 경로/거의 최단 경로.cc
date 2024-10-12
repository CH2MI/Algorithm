#include <iostream>
#include <vector> 
#include <queue>
#define INF (int)1e9
using namespace std;

int N, M;
vector<vector<int>> adj;
vector<int> dist;
vector<bool> visited;

void Dijkstra(int S, int D) {
	dist.assign(N, INF);
	dist[S] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, S });

	while (!pq.empty()) {
		auto [cur_dist, cur_node] = pq.top();
		pq.pop();
		cur_dist = -cur_dist;

		if (dist[cur_node] != cur_dist) continue;

		for (int nxt_node = 0; nxt_node < N; nxt_node++) {
			if (!adj[cur_node][nxt_node]) continue;
			int nxt_dist = cur_dist + adj[cur_node][nxt_node];
			if (nxt_dist < dist[nxt_node]) {
				dist[nxt_node] = nxt_dist;
				pq.push({ -nxt_dist, nxt_node });
			}
		}
	}
}

void DFS(int n) {
	if (visited[n]) return;

	visited[n] = true;

	for (int i = 0; i < N; i++) {
		if (!adj[i][n]) continue;

		// 최단 경로에 포함된 경로
		if (dist[i] + adj[i][n] == dist[n]) {
			adj[i][n] = 0;
			DFS(i);
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	while (true) {
		cin >> N >> M;
		if (!N && !M) break;

		int S, D;
		cin >> S >> D;

		adj.assign(N, vector<int>(N));

		for (int i = 0; i < M; i++) {
			int u, v, p;
			cin >> u >> v >> p;
			adj[u][v] = p;
		}

		Dijkstra(S, D);
		visited.assign(N, false);
		DFS(D);
		Dijkstra(S, D);

		if (dist[D] == INF) cout << "-1\n";
		else cout << dist[D] << '\n';
	}
}