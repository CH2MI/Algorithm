#include <iostream>
#include <vector>
#define INF (int)1e9
using namespace std;

int n;
vector<vector<int>> adj;

void Floyd() {
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j) {
					adj[i][j] = 0;
				}
				else {
					adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int m;
	cin >> n >> m;

	adj.assign(n, vector<int>(n, INF));

	for (int i = 0; i < m; i++) {
		int s, e, w;
		cin >> s >> e >> w;
		adj[s - 1][e - 1] = min(adj[s - 1][e - 1], w);
	}

	Floyd();

	for (const auto& i : adj) {
		for (int j : i) {
			if (j == INF) cout << "0 ";
			else cout << j << ' ';
		}
		cout << '\n';
	}
}