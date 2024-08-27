#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

vector<vector<int>> adj;
vector<vector<int>> parent;
vector<int> level;
int maxlevel;

int LCA(int a, int b) {
	if (level[a] < level[b]) swap(a, b);
	int diff = level[a] - level[b];

	// 두 노드의 높이를 맞춰준다.
	for (int i = 0; diff; i++) {
		if (diff & 1) a = parent[a][i];
		diff >>= 1;
	}

	if (a == b) return a;

	// 공통 조상을 찾는다.
	for (int i = maxlevel; i >= 0; i--) {
		if (parent[a][i] != parent[b][i]) {
			a = parent[a][i];
			b = parent[b][i];
		}
	}
	return parent[a][0];
}

void DFS(int p, int s) {
	level[s] = level[p] + 1;
	parent[s][0] = p;

	for (int i = 1; i <= maxlevel; i++) {
		parent[s][i] = parent[parent[s][i - 1]][i - 1];
	}

	for (const auto& i : adj[s]) {
		if (i == p) continue;
		DFS(s, i);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int N, M;
	cin >> N;
	maxlevel = (int)floor(log2(N));

	adj.assign(N + 1, vector<int>());
	parent.assign(N + 1, vector<int>(maxlevel + 1, 0));
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