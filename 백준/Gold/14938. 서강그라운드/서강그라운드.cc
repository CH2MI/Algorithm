#include <iostream>
#include <vector>
#include <queue>
#define INF 1 << 30
using namespace std;

int n, m, r;
vector<int> item;
vector<vector<pair<int, int>>> adj;

void dijkstra(vector<int>& dist, int start) {
	priority_queue<pair<int, int>> pq;
	dist[start] = 0;
	pq.emplace(0, start);
	while (!pq.empty()) {
		int cur_dist = -pq.top().first;
		int cur_node = pq.top().second;
		pq.pop();

		if (dist[cur_node] != cur_dist) continue;

		for (auto i : adj[cur_node]) {
			int nxt_node = i.first;
			int nxt_dist = cur_dist + i.second;
			if (nxt_dist < dist[nxt_node]) {
				dist[nxt_node] = nxt_dist;
				pq.emplace(-nxt_dist, nxt_node);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n >> m >> r;
	item.assign(n, 0);

	for (int i = 0; i < n; i++) {
		cin >> item[i];
	}

	adj.assign(n, vector<pair<int, int>>());

	for (int i = 0; i < r; i++) {
		int s, e, d;
		cin >> s >> e >> d;
		adj[s - 1].emplace_back(e - 1, d);
		adj[e - 1].emplace_back(s - 1, d);
	}

	vector<vector<int>> dist(n, vector<int>(n, INF));

	int ret = 0;
	for (int i = 0; i < n; i++) {
		dijkstra(dist[i], i);

		int t = 0;
		for (int j = 0; j < n; j++) {
			if (dist[i][j] <= m) t += item[j];
		}

		ret = max(ret, t);
	}
	cout << ret;
}