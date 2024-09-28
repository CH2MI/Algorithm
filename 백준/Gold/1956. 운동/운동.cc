#include <iostream>
#include <vector>
#include <queue>
#define INF (int)1e9
using namespace std;

int V;
vector<vector<pair<int, int>>> adj;
vector<vector<int>> dist;

void Dijkstra(int S) {
	dist[S][S] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, S });

	while (!pq.empty()) {
		auto [cur_dist, cur_node] = pq.top();
		pq.pop();

		cur_dist *= -1;

		if (dist[S][cur_node] != cur_dist) continue;

		for (const auto& [nxt_node, weight] : adj[cur_node]) {
			int nxt_dist = cur_dist + weight;
			if (nxt_dist < dist[S][nxt_node]) {
				dist[S][nxt_node] = nxt_dist;
				pq.push({ -nxt_dist, nxt_node });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int E;
	cin >> V >> E;

	adj.assign(V, vector<pair<int, int>>());

	for (int i = 0; i < E; i++) {
		int s, e, w;
		cin >> s >> e >> w;
		adj[s - 1].push_back({ e - 1, w });
	}

	dist.assign(V, vector<int>(V, INF));
	for (int i = 0; i < V; i++) {
		Dijkstra(i);
	}

	int mn = INF;

	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			if (i == j) continue;
			mn = min(mn, dist[i][j] + dist[j][i]);
		}
	}
	if (mn == INF) cout << "-1";
	else cout << mn;
}