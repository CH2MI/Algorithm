#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#define INF INT_MAX
using namespace std;

void dijkstra(vector<vector<pair<int, int>>>& v, vector<int>& dist, int start) {
	priority_queue<pair<int, int>> pq;

	dist[start] = 0;
	pq.push({ 0, start });

	while (!pq.empty()) {
		int cur_dist = -pq.top().first;
		int cur_node = pq.top().second;
		pq.pop();

		if (cur_dist != dist[cur_node]) continue;

		for (auto i : v[cur_node]) {
			int nxt_dist = cur_dist + i.second;
			if (nxt_dist < dist[i.first]) {
				dist[i.first] = nxt_dist;
				pq.push({ -nxt_dist, i.first });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int N, M;
	cin >> N >> M;
	vector<vector<pair<int, int>>> v(N);

	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a - 1].emplace_back(b - 1, c);
	}

	int s, e;
	cin >> s >> e;

	vector<int> dist(N, INF);
	dijkstra(v, dist, s - 1);

	cout << dist[e - 1];
}