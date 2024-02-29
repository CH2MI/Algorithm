#include <iostream>
#include <vector>
#include <tuple>
#define INF 1 << 25
using namespace std;

bool bellman_ford(vector<tuple<int, int, int>>& v, vector<int>& dist, int V) {
	dist[0] = 0;

	int L = v.size();
	for (int i = 0; i < V; i++) {
		for (auto j : v) {
			int cur_node = get<0>(j);
			int nxt_node = get<1>(j);
			int cur_dist = get<2>(j);

			if (dist[nxt_node] > dist[cur_node] + cur_dist) {
				dist[nxt_node] = dist[cur_node] + cur_dist;

				if (i == V - 1) return true;
			}
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int T;
	cin >> T;
	
	for (int test_case = 0; test_case < T; ++test_case) {

		int N, M, W;
		cin >> N >> M >> W;

		vector<tuple<int, int, int>> v(N);

		for (int i = 0; i < M; i++) {
			int s, e, t;
			cin >> s >> e >> t;
			v.emplace_back(s - 1, e - 1, t);
			v.emplace_back(e - 1, s - 1, t);
		}

		for (int i = 0; i < W; i++) {
			int s, e, t;
			cin >> s >> e >> t;
			v.emplace_back(s - 1, e - 1, -t);
		}
		bool b = false;
		vector<int>dist(N, INF);
		b = bellman_ford(v, dist, N);
		
		if (b) cout << "YES\n";
		else cout << "NO\n";
	}
}