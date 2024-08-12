#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

#define INF (int)1e9

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

int N;
vector<vector<int>> adj;

int Dijkstra() {
	priority_queue<tuple<int, int, int>> pq;
	vector<vector<int>> dist(N, vector<int>(N, INF));
	dist[0][0] = adj[0][0];
	pq.push({ -dist[0][0], 0, 0 });
	

	while (!pq.empty()) {
		auto [cur_dist, cur_y, cur_x] = pq.top();
		pq.pop();
		cur_dist *= -1;

		if (dist[cur_y][cur_x] != cur_dist) continue;

		for (int i = 0; i < 4; i++) {
			int nxt_y = cur_y + dy[i];
			int nxt_x = cur_x + dx[i];

			if (nxt_x < 0 || nxt_x >= N || nxt_y < 0 || nxt_y >= N) continue;

			int nxt_dist = cur_dist + adj[nxt_y][nxt_x];
			if (nxt_dist < dist[nxt_y][nxt_x]) {
				dist[nxt_y][nxt_x] = nxt_dist;
				pq.push({ -nxt_dist, nxt_y, nxt_x });
			}
		}
	}

	return dist[N - 1][N - 1];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int T = 1;
	while (true) {
		cin >> N;
		if (!N) break;

		adj.assign(N, vector<int>(N, 0));

		for (auto& i : adj) {
			for (auto& j : i)
				cin >> j;
		}
		
		cout << "Problem " << T++ << ": " << Dijkstra() << '\n';
	}
}