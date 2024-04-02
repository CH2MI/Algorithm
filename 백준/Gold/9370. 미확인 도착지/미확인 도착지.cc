#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 1e9
using namespace std;

vector<vector<pair<int, int>>> adj;
int S, G, H;

void dijkstra(vector<int>& dist, int start) {
	priority_queue<pair<int, int>> pq;
	dist[start] = 0;
	pq.emplace(0, start);

	while (!pq.empty()) {
		auto [cur_dist, cur_node] = pq.top();
		pq.pop();
		cur_dist = -cur_dist;

		if (dist[cur_node] != cur_dist) continue;

		for (auto [nxt_node, nxt_dist] : adj[cur_node]) {
			nxt_dist += cur_dist;

			if (nxt_dist < dist[nxt_node]) {
				dist[nxt_node] = nxt_dist;
				pq.emplace(-nxt_dist, nxt_node);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int T;
	cin >> T;
	for (int tc = 0; tc < T; ++tc) {
		int n, m, t, D;
		cin >> n >> m >> t;

		adj.assign(n, vector<pair<int, int>>());
		vector<int> list;

		cin >> S >> G >> H;

		for (int i = 0; i < m; i++) {
			int s, e, d;
			cin >> s >> e >> d;
			if ((s == G && e == H) || (s == H && e == G)) {
				D = d;
			}
			adj[s - 1].emplace_back(e - 1, d);
			adj[e - 1].emplace_back(s - 1, d);
		}

		for (int i = 0; i < t; i++) {
			int a;
			cin >> a;
			list.push_back(a - 1);
		}

		sort(list.begin(), list.end());

		vector<vector<int>> dist(3, vector<int>(n, INF));

		// 시작점, G, H로 다익스트라를 한다.
		dijkstra(dist[0], S - 1);
		dijkstra(dist[1], G - 1);
		dijkstra(dist[2], H - 1);

		for (auto i : list) {

			// G-H로 가는 경로가 없으면 건너 뛴다.
			if (dist[0][G - 1] == INF) continue;
			if (dist[0][H - 1] == INF) continue;

			// 해당 경로를 거쳐서 가는 길이 최단경로와 같으면 출력한다.
			int distance1 = dist[0][G - 1] + D + dist[2][i];
			int distance2 = dist[0][H - 1] + D + dist[1][i];

			if (distance1 == dist[0][i] || distance2 == dist[0][i]) cout << i + 1 << ' ';
		}		
		cout << '\n';
	}

}
