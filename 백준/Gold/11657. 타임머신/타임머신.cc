#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#define INF (int)1e9
using namespace std;

int N, M;
vector<tuple<int, int, int>> edges;
vector<long long> dist;

bool BellmanFord() {
	dist[0] = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			auto& [s, e, v] = edges[j];

			if (dist[s] == INF) continue;
			if (dist[e] > dist[s] + v) {
				dist[e] = dist[s] + v;

				if (i == N - 1) return true;
			}
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	edges.assign(M, tuple<int, int, int>());
	dist.assign(N, INF);

	for (auto& i : edges) {
		int s, e, v;
		cin >> s >> e >> v;
		i = { s - 1, e - 1, v };
	}

	if (BellmanFord()) cout << "-1";
	else {
		for (int i = 1; i < N; i++) {
			if (dist[i] == INF) cout << "-1\n";
			else cout << dist[i] << '\n';
		}
	}
}