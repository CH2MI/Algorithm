#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
int dy[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };

vector<vector<int>> adj;
vector<vector<bool>> visited;

int w, h;

void BFS(int sx, int sy) {
	queue<pair<int, int>> q;
	q.push({ sx, sy });

	while (!q.empty()) {
		auto [x, y] = q.front();
		q.pop();

		if (x < 0 || x >= h || y < 0 || y >= w) continue;
		if (!adj[x][y]) continue;
		if (visited[x][y]) continue;

		visited[x][y] = true;

		for (int k = 0; k < 8; k++) {
			int i = x + dx[k];
			int j = y + dy[k];
			q.emplace(i, j);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	while (true) {
		cin >> w >> h;
		if (!w && !h) break;

		adj.assign(h, vector<int>(w, 0));
		visited.assign(h, vector<bool>(w, false));

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> adj[i][j];
			}
		}

		int cnt = 0;

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (!adj[i][j]) continue;
				if (visited[i][j]) continue;

				cnt++;
				BFS(i, j);
			}
		}

		cout << cnt << '\n';
	}
}