#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define INF (int)1e9

int N, K, P;
vector<vector<pair<int, int>>> adj;

bool solve(int mid) {
	vector<int> Cost(N, INF);
	priority_queue<pair<int, int>> pq;

	Cost[0] = 0;
	pq.push({ 0, 0 });
	while (!pq.empty()) {
		auto [cur_cost, cur_node] = pq.top();
		pq.pop();
		cur_cost *= -1;

		if (cur_cost != Cost[cur_node]) continue;

		for (auto i : adj[cur_node]) {
			int nxt_cost = cur_cost + (i.second > mid);

			if (nxt_cost < Cost[i.first]) {
				Cost[i.first] = nxt_cost;
				pq.push({ -nxt_cost, i.first });
			}
		}
	}
	return Cost[N - 1] <= P;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> N >> K >> P;
	adj.assign(N, vector<pair<int, int>>());

	for (int i = 0; i < K; i++) {
		int s, e, c;
		cin >> s >> e >> c;

		adj[s - 1].push_back({ e - 1, c });
		adj[e - 1].push_back({ s - 1, c });
	}

	int lo = -1;
	int hi = 1e6 + 1;
	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		if (solve(mid)) hi = mid;
		else lo = mid;
	}
	if (hi == 1e6 + 1) cout << "-1";
	else cout << hi;
} 