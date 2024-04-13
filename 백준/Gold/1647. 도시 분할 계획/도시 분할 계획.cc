#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N;
vector<vector<pair<int, int>>> adj;

int prim() {
	vector<bool> visited(N);
	priority_queue<pair<int, int>> pq;
	vector<int> list(N);
	int sum = 0;
	int cnt = 0;

	pq.emplace(0, 0);

	while (!pq.empty()) {
		auto [cur_dist, cur_node] = pq.top();
		pq.pop();

		if (visited[cur_node]) continue;

		visited[cur_node] = 1;
		sum -= cur_dist;
		list[cnt] = -cur_dist;

		if (++cnt == N) break;

		for (auto [nxt_node, nxt_dist] : adj[cur_node]) {
			if (visited[nxt_node]) continue;
			pq.emplace(-nxt_dist, nxt_node);
		}
	}

	return sum - *max_element(list.begin(), list.end());
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	int M;
	cin >> N >> M;

	adj.assign(N, vector<pair<int, int>>());

	for (int i = 0; i < M; i++) {
		int s, e, d;
		cin >> s >> e >> d;
		adj[s - 1].emplace_back(e - 1, d);
		adj[e - 1].emplace_back(s - 1, d);
	}

	cout << prim();
}