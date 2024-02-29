#include<iostream>
#include <vector>
#include<queue>
#define INF 1000000
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

	// 역방향으로 된 인접행렬을 하나 더 만들어 x 기준으로 다익스트라를 두번 돌린다.
	vector<vector<pair<int, int>>> adj(N);
	vector<vector<pair<int, int>>> radj(N);

	vector<int> dist(N);
	vector<int> rdist(N);

	for (int i = 0; i < N; i++) {
		dist[i] = rdist[i] = INF;
	}

	for (int i = 0; i < M; i++) {
		int s, e, t;
		cin >> s >> e >> t;
		adj[s - 1].push_back({ e - 1, t });
		radj[e - 1].push_back({ s - 1, t });
	}

	// 정방향으로 다익스트라를 돌린다.
	dijkstra(adj, X - 1, dist, N);

	// 역방향으로 다익스트라를 돌린다.
	dijkstra(radj, X - 1, rdist, N);

	// 거리의 최댓값을 구한다.
	int max = 0;
	for (int i = 0; i < N; i++) {
		int t = dist[i] + rdist[i];
		if (max < t) max = t;
	}
	cout << max;
}