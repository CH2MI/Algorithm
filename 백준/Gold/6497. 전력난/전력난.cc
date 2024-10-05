#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int m, n;
vector<vector<pair<int, int>>> adj;

int Prim() {
	vector<bool> visited(m, false);
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, 0 });
	int cnt = 0;
	int sum = 0;
	while (!pq.empty()) {
		auto [cur_dist, cur_node] = pq.top();
		pq.pop();
		cur_dist = -cur_dist;

		if (visited[cur_node]) continue;

		visited[cur_node] = true;
		sum += cur_dist;
		if (++cnt == m) break;

		for (const auto& [nxt_node, nxt_dist] : adj[cur_node]) {
			if (visited[nxt_node]) continue;
			pq.push({ -nxt_dist, nxt_node });
		}
	}
	return sum;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	while (true) {
		cin >> m >> n;
		if (!m && !n) break;

		adj.assign(m, vector<pair<int, int>>());
		int sum = 0;

		for (int i = 0; i < n; i++) {
			int s, e, w;
			cin >> s >> e >> w;
			adj[s].push_back({ e, w });
			adj[e].push_back({ s, w });
			sum += w;
		}

		cout << sum - Prim() << '\n';
	}
}