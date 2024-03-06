#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define INF 1 << 28
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

	int N, E;
	cin >> N >> E;
	vector<vector<pair<int, int>>> v(N);

	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a - 1].emplace_back(b - 1, c);
		v[b - 1].emplace_back(a - 1, c);
	}

	// 1, u, v 에서 각각 다익스트라를 돌린다.
	int U, V;
	cin >> U >> V;
	vector<int> dist1(N, INF), distu(N, INF), distv(N, INF);
	dijkstra(v, dist1, 0);
	dijkstra(v, distu, U - 1);
	dijkstra(v, distv, V - 1);

	// 1 u v n, 1 v u n 중 최단 경로를 찾는다
	int r1 = dist1[U - 1] + distu[V - 1] + distv[N - 1];
	int r2 = dist1[V - 1] + distv[U - 1] + distu[N - 1];

	int m = min({ r1, r2, INF });
	if (m == INF) cout << "-1";
	else cout << m;
}