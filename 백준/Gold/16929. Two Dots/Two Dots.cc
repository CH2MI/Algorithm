#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N, M;
vector<string> adj;
vector<vector<int>> visited;

int X[4] = { -1, 1, 0, 0 };
int Y[4] = { 0, 0, -1, 1 };

bool is_Cycle(int i, int j, int pi, int pj, char c) {
	visited[i][j] = 1;

	for (int k = 0; k < 4; k++) {
		int x = i + X[k];
		int y = j + Y[k];
		if (x < 0 || x >= N || y < 0 || y >= M) continue;
		if (x == pi && y == pj) continue;
		if (adj[x][y] != c) continue;

		// 사이클이 생겼다.
		if (visited[x][y]) return true;

		if (is_Cycle(x, y, i, j, c)) return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> N >> M;
	cin.ignore();
	adj.assign(N, string());
	for (int i = 0; i < N; i++) 
		getline(cin, adj[i]);

	bool f = false;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visited.assign(N, vector<int>(M));
			if (is_Cycle(i, j, -1, -1, adj[i][j])) 
				f = true;
			
		}
	}

	if (f) cout << "Yes";
	else cout << "No";
}