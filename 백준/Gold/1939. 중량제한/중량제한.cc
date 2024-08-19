#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, S, E;
vector<vector<pair<int, int>>> adj;


bool solve(int mid) {
	queue<int> q;
	vector<bool> visited(N);
	q.push(S - 1);

	while (!q.empty()) {
		int cur_node = q.front();
		q.pop();

		if (cur_node == E - 1) return true;

		if (visited[cur_node]) continue;
		visited[cur_node] = true;

		for (const auto& [nxt_node, w] : adj[cur_node]) {
			if (w < mid) continue;
			q.push(nxt_node);
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> N >> M;
	adj.assign(N, vector<pair<int, int>>());

	for (int i = 0; i < M; i++) {
		int A, B, C;
		cin >> A >> B >> C;
		adj[A - 1].push_back({ B - 1, C });
		adj[B - 1].push_back({ A - 1, C });
	}
	cin >> S >> E;

	int lo = 0, hi = (int)1e9 + 1;
	while (lo + 1 < hi) {
		int mid = lo + (hi - lo) / 2;
		if (solve(mid)) lo = mid;
		else hi = mid;
	}
	cout << lo;
}