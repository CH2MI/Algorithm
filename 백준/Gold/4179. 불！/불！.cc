#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

int R, C;
vector<string> v;
queue<tuple<int, int, int>> fire, jihun;
vector<vector<int>> visited;

void bfs_fire() {
	while (!fire.empty()) {
		int i = get<0>(fire.front());
		int j = get<1>(fire.front());
		int cnt = get<2>(fire.front());
		fire.pop();

		if (i < 0 || i >= R || j < 0 || j >= C) continue;
		if (v[i][j] == '#') continue;
		if (visited[i][j] > 0) continue;

		visited[i][j] = cnt;

		for (int k = 0; k < 4; k++) {
			int x = i + dx[k];
			int y = j + dy[k];

			fire.emplace(x, y, cnt + 1);
		}
	}
}

int bfs_jihun() {
	while (!jihun.empty()) {
		int i = get<0>(jihun.front());
		int j = get<1>(jihun.front());
		int cnt = get<2>(jihun.front());
		jihun.pop();

		if (i < 0 || i >= R || j < 0 || j >= C) continue;
		if (v[i][j] == '#') continue;
		if (visited[i][j] && visited[i][j] <= cnt) continue;
        visited[i][j] = -1;    

		// 도착!
		if (i == 0 || i == R - 1 || j == 0 || j == C - 1) return cnt;

		for (int k = 0; k < 4; k++) {
			int x = i + dx[k];
			int y = j + dy[k];

			jihun.emplace(x, y, cnt + 1);
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> R >> C;

	v.assign(R, string());
	visited.assign(R, vector<int>(C));

	for (int i = 0; i < R; i++) {
		cin >> v[i];
		for (int j = 0; j < C; j++) {
			if (v[i][j] == 'F') fire.emplace(i, j, 1);
			else if (v[i][j] == 'J') {
				jihun.emplace(i, j, 1);
				v[i][j] == '.';
			}
		}
	}

	bfs_fire();

	int cnt = bfs_jihun();

	if (cnt == -1) cout << "IMPOSSIBLE";
	else cout << cnt;
}