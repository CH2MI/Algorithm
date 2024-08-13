#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF (int)1e9

int N, M;
vector<vector<pair<int, int>>> adj;
vector<pair<int, int>> dist;

void Dijkstra() {
	dist.assign(N, { INF, -1 });
	priority_queue<pair<int, int>> pq;
	dist[0].first = 0;
	pq.push({ 0, 0 });
	
	while (!pq.empty()) {
		auto [cur_dist, cur_node] = pq.top();
		pq.pop();
		cur_dist *= -1;

		if (cur_dist != dist[cur_node].first) continue;

		for (auto [nxt_node, nxt_dist] : adj[cur_node]) {
			nxt_dist += cur_dist;
			if (nxt_dist < dist[nxt_node].first) {
				dist[nxt_node] = { nxt_dist, cur_node };
				pq.push({ -nxt_dist, nxt_node });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> N >> M;
	adj.assign(N, vector<pair<int, int>>());

	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a - 1].push_back({ b - 1, c });
		adj[b - 1].push_back({ a - 1, c });
	}

	Dijkstra();

	cout << N - 1 << '\n';
	for (int i = 1; i < N; i++) {
		cout << dist[i].second + 1 << ' ' << i + 1 << '\n';
	}
}