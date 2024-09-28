#include <iostream>
#include <vector>
#include <queue>
#define INF (int)1e9
using namespace std;

int V;
vector<vector<int>> adj;

void Floyd() {
	for (int k = 0; k < V; k++) {
		for (int i = 0; i < V; i++) {
			for (int j = 0; j < V; j++) {
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int E;
	cin >> V >> E;

	adj.assign(V, vector<int>(V, INF));

	for (int i = 0; i < E; i++) {
		int s, e, w;
		cin >> s >> e >> w;
		adj[s - 1][e - 1] = w;
	}

	Floyd();

	int mn = INF;

	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			if (i == j) continue;
			mn = min(mn, adj[i][j] + adj[j][i]);
		}
	}
	if (mn == INF) cout << "-1";
	else cout << mn;
}