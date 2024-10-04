#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

bool Is_Tree(int p, int n) {
	visited[n] = true;

	bool f = true;
	for (auto& i : adj[n]) {
		if (i == p) continue;

		// 싸이클이 생긴 경우
		if (visited[i]) {
			f = false;
			continue;
		}

		f &= Is_Tree(n, i);
	}
	return f;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int tc = 1;
	while (true) {
		int n, m;
		cin >> n >> m;

		if (!n && !m) break;

		adj.assign(n, vector<int>());

		for (int i = 0; i < m; i++) {
			int s, e;
			cin >> s >> e;
			adj[s - 1].push_back(e - 1);
			adj[e - 1].push_back(s - 1);
		}
		
		visited.assign(n, false);
		int cnt = 0;

		for (int i = 0; i < n; i++) {
			if (visited[i]) continue;
			if (Is_Tree(-1, i)) cnt++;
		}

		cout << "Case " << tc++ << ": ";
		if (!cnt) cout << "No trees.\n";
		else if (cnt == 1) cout << "There is one tree.\n";
		else cout << "A forest of " << cnt << " trees.\n";
	}
}