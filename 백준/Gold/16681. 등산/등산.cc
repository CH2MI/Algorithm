#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

#define INF LLONG_MAX

vector<vector<pair<int, int>>> adj;
vector<int> heights;

int N, M, D, E;

void Dijkstra(vector<long long>& dist, int start) {
	priority_queue<pair<long long, int>> pq;
	dist[start] = 0;
	pq.push({ 0, start });
	while (!pq.empty()) {
		auto [cur_dist, cur_node] = pq.top();
		pq.pop();
		cur_dist *= -1;

		if (dist[cur_node] != cur_dist) continue;

		for (auto& [nxt_node, d] : adj[cur_node]) {
			if (heights[cur_node] < heights[nxt_node]) {
				long long nxt_dist = cur_dist + d;
				if (nxt_dist < dist[nxt_node]) {
					dist[nxt_node] = nxt_dist;
					pq.push({ -nxt_dist, nxt_node });
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> N >> M >> D >> E;
	heights.assign(N, 0);
	adj.assign(N, vector<pair<int, int>>());
	vector<long long> upDist(N, INF), downDist(N, INF);
	
	for (auto& i : heights)
		cin >> i;

	for (int i = 0; i < M; i++) {
		int a, b, n;
		cin >> a >> b >> n;
		adj[a - 1].push_back({ b - 1, n });
		if (a != b) adj[b - 1].push_back({ a - 1, n });
	}

	Dijkstra(upDist, 0);
	Dijkstra(downDist, N - 1);

	long long mx = -INF;
	for (int i = 1; i < N - 1; i++) {
		auto up = upDist[i];
		auto down = downDist[i];
		if (up == INF || down == INF) continue;
		auto h = heights[i];
		mx = max(mx, h * E - (up + down) * D);
	}
	if (mx == -INF) cout << "Impossible";
	else cout << mx;
}