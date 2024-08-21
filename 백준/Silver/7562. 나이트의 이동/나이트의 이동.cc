#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int dx[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int dy[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

int I;
vector<vector<bool>> visited;
int sx, sy, ex, ey;

int BFS() {
	visited = vector<vector<bool>>(I, vector<bool>(I));
	queue<tuple<int, int, int>> q;
	q.emplace(0, sx, sy);
	while (!q.empty()) {
		auto [cnt, x, y] = q.front();
		q.pop();

		if (x == ex && y == ey) return cnt;
		if (x < 0 || x >= I || y < 0 || y >= I) continue;
		if (visited[x][y]) continue;
		visited[x][y] = true;

		for (int k = 0; k < 8; k++) {
			int i = x + dx[k];
			int j = y + dy[k];
			q.emplace(cnt + 1, i, j);
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int T;
	cin >> T;

	while (T--) {
		cin >> I >> sx >> sy >> ex >> ey;
		cout << BFS() << '\n';
	}
}
