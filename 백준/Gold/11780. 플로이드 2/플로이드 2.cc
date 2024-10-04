#include <iostream>
#include <vector>
#define INF (int)1e9
using namespace std;

int n;
vector<vector<int>> adj;
vector<vector<int>> trace;
vector<int> v;

void Floyd() {
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j) {
					adj[i][j] = 0;
					continue;
				}
				int w = adj[i][k] + adj[k][j];
				if (adj[i][j] > w) {
					adj[i][j] = w;
					trace[i][j] = k;
				}
			}
		}
	}
}

void DFS(int s, int e) {
	if (trace[s][e] == -1) {
		v.push_back(s);
		v.push_back(e);
		return;	
	}
	DFS(s, trace[s][e]);
	v.pop_back();
	DFS(trace[s][e], e);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int m;
	cin >> n >> m;

	adj.assign(n, vector<int>(n, INF));
	trace.assign(n, vector<int>(n, -1));


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

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (adj[i][j] == 0 || adj[i][j] == INF) {
				cout << "0\n";
				continue;
			}
			v.clear();
			DFS(i, j);
			cout << v.size() << ' ';
			for (const auto& i : v) cout << i + 1 << ' ';
			cout << '\n';
		}
	}
}