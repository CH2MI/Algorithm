#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#define INF INT_MAX
using namespace std;

void dijkstra(vector<vector<pair<int, int>>>& arr, int start, vector<int>& dist, int N) {
	priority_queue<pair<int, int>> pq;
	dist[start] = 0;
	pq.push({ 0, start });

	while (!pq.empty()) {
		int cur_dist = -pq.top().first;
		int cur_node = pq.top().second;
		pq.pop();

		if (cur_dist != dist[cur_node]) continue;

		int l = arr[cur_node].size();
		for (int i = 0; i < l; i++) {
			int nxt_dist = cur_dist + arr[cur_node][i].second;
			int j = arr[cur_node][i].first;
			if (nxt_dist < dist[j]) {
				dist[j] = nxt_dist;
				pq.push({ -nxt_dist, j });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int N, M, X;
	cin >> N >> M >> X;

	vector<vector<pair<int, int>>> adj(N);

	vector<int> dist(N, INF);

	for (int i = 0; i < M; i++) {
		int s, e, t;
		cin >> s >> e >> t;
		adj[s - 1].push_back({ e - 1, t });
	}

	dijkstra(adj, X - 1, dist, N);

	for (auto i : dist) {
		if (i == INF) cout << "INF\n";
		else cout << i << '\n';
	}
}