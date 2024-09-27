#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int n;
vector<pair<int, int>> adj;

bool Dijkstra() {
	priority_queue<int> pq;
	vector<int> visited(n + 2);
	pq.push(0);

	while (!pq.empty()) {
		auto point = pq.top();
		pq.pop();

		if (point == n + 1) return true;
		if (visited[point]) continue;

		visited[point] = true;

		for (int i = 0; i < n + 2; i++) {
			if (point == i) continue;
			int dist = abs(adj[point].first - adj[i].first) + abs(adj[point].second - adj[i].second);
			if (dist <= 1000) {
				pq.push(i);
			}
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int t;
	cin >> t;

	while (t--) {
		cin >> n;

		adj.assign(n + 2, pair<int, int>());

		for (auto& [x, y] : adj) {
			cin >> x >> y;
		}

		if (Dijkstra()) cout << "happy\n";
		else cout << "sad\n";
	}
}