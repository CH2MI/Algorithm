#include <iostream>
#include <vector>
#include <queue>
#define INF (int)1e9
using namespace std;



vector<vector<int>> adj;
vector<int> dist;
int N;
 
void Dijkstra(int s) {
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, s });
	dist[s] = 0;

	while (!pq.empty()) {
		auto [cur_dist, cur_node] = pq.top();
		pq.pop();
		cur_dist *= -1;

		if (dist[cur_node] != cur_dist) continue;

		for (const auto& nxt_node : adj[cur_node]) {
			int nxt_dist = cur_dist + 1;

			if (nxt_dist < dist[nxt_node]) {
				dist[nxt_node] = nxt_dist;
				pq.push({ -nxt_dist, nxt_node });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int M, K, X;
	cin >> N >> M >> K >> X;

	adj.assign(N, vector<int>());
	dist.assign(N, INF);

	for (int i = 0; i < M; i++) {
		int s, e;
		cin >> s >> e;
		adj[s - 1].push_back(e - 1);
	}

	Dijkstra(X - 1);

	vector<int> ans;
	for (int i = 0; i < N; i++) {
		if (dist[i] == K) {
			ans.push_back(i + 1);
		}
	}

	if (!ans.size()) {
		cout << "-1";
	}
	else {
		for (auto i : ans) cout << i << '\n';
	}
}