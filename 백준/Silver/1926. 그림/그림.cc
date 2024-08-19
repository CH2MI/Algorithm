#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> pic;
vector<vector<bool>> visited;
int n, m;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

int bfs(int i, int j) {
	queue<pair<int, int>> q;
	q.push({ i, j });
	
	int cnt = 0;
	while (!q.empty()) {
		auto [x, y] = q.front();
		q.pop();

		if (x < 0 || x >= n || y < 0 || y >= m) continue;
		if (!pic[x][y]) continue;
		if (visited[x][y]) continue;
		visited[x][y] = true;
		cnt++;

		for (int k = 0; k < 4; k++) {
			i = x + dx[k];
			j = y + dy[k];
			q.push({ i, j });
		}
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n >> m;

	pic.assign(n, vector<int>(m, 0));
	for (auto& i : pic)
		for (auto& j : i)
			cin >> j;

	visited.assign(n, vector<bool>(m, false));

	int cnt = 0;
	int mx = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!pic[i][j]) continue;
			if (visited[i][j]) continue;
			mx = max(mx, bfs(i, j));
			cnt++;
		}
	}
	cout << cnt << '\n' << mx;
}