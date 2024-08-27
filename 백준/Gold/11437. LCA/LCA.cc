#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj;
vector<int> parent;
vector<int> level;

int LCA(int a, int b) {
	while (level[a] < level[b])
		b = parent[b];
	while (level[a] > level[b])
		a = parent[a];

	while (a != b) {
		a = parent[a];
		b = parent[b];
	}
	return a;
}

void DFS(int p, int s) {
	parent[s] = p;
	level[s] = level[p] + 1;

	for (const auto& i : adj[s]) {
		if (i == p) continue;
		DFS(s, i);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int N, M;
	cin >> N;

	adj.assign(N + 1, vector<int>());
	parent.assign(N + 1, 0);
	level.assign(N + 1, 0);

	for (int i = 0; i < N - 1; i++) {
		int s, e;
		cin >> s >> e;
		adj[s].push_back(e);
		adj[e].push_back(s);
	}
	DFS(0, 1);

	cin >> M;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		cout << LCA(a, b) << '\n';
	}

}