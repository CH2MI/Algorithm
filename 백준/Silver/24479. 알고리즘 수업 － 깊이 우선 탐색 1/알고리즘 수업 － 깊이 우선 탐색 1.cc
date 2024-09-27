#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<vector<int>> adj;
vector<int> visited;
int cnt = 1;

void DFS(int n) {
	visited[n] = cnt++;

	sort(adj[n].begin(), adj[n].end());

	for (auto i : adj[n]) {
		if (visited[i]) continue;
		DFS(i);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int M, R;
	cin >> N >> M >> R;

	adj.assign(N, vector<int>());
	visited.assign(N, 0);

	for (int i = 0; i < M; i++) {
		int s, e;
		cin >> s >> e;
		adj[s - 1].push_back(e - 1);
		adj[e - 1].push_back(s - 1);
	}

	DFS(R - 1);

	for (auto i : visited) cout << i << '\n';

}