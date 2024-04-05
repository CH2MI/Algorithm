#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<pair<int, int>>> adj;

int V;

int prim() {
	priority_queue<pair<int, int>> pq;
	pq.emplace(0, 0);
	int cnt = 0;
	int sum = 0;
	vector<bool> visited(V);
	

	while (!pq.empty()) {
		auto [cur_dist, cur_node] = pq.top();
		pq.pop();
		cur_dist = -cur_dist;

		if (visited[cur_node]) continue;
		
		visited[cur_node] = 1;
		sum += cur_dist;

		if (++cnt == V) break;

		for (auto& [nxt_node, nxt_dist] : adj[cur_node]) {
			if (visited[nxt_node]) continue;
			pq.emplace(-nxt_dist, nxt_node);
		}
	}
	return sum;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int E;
	cin >> V >> E;

	adj.assign(V, vector<pair<int, int>>());

	for (int i = 0; i < E; i++) {
		int s, e, d;
		cin >> s >> e >> d;
		adj[s - 1].emplace_back(e - 1, d);
		adj[e - 1].emplace_back(s - 1, d);
	}

	cout << prim();
}