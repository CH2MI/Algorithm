#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

int R, C;
int Dx, Dy;
queue<tuple<int, int, int>> hedgehog, water;
vector<string> v;
vector<vector<int>> visited;

void bfs_water() {
	while (!water.empty()) {
		int i = get<0>(water.front());
		int j = get<1>(water.front());
		int cnt = get<2>(water.front());
		water.pop();

		if (i < 0 || i >= R || j < 0 || j >= C) continue;
		if (v[i][j] == 'X' || v[i][j] == 'D') continue;
		if (visited[i][j] > 0) continue;

		visited[i][j] = cnt;

		for (int k = 0; k < 4; k++) {
			water.emplace(i + dx[k], j + dy[k], cnt + 1);
		}
	}
}

int bfs_hedgehog() {
	while (!hedgehog.empty()) {
		int i = get<0>(hedgehog.front());
		int j = get<1>(hedgehog.front());
		int cnt = get<2>(hedgehog.front());
		hedgehog.pop();

		if (i < 0 || i >= R || j < 0 || j >= C) continue;
		if (v[i][j] == 'X') continue;
		if (visited[i][j] && visited[i][j] <= cnt) continue;
		visited[i][j] = -1;

		// 도착!
		if (i == Dx && j == Dy) return cnt;

		for (int k = 0; k < 4; k++) {
			hedgehog.emplace(i + dx[k], j + dy[k], cnt + 1);
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> R >> C;

	v.assign(R, string());
	visited.assign(R, vector<int>(C, 0));

	for (int i = 0; i < R; i++) {
		cin >> v[i];
		for (int j = 0; j < C; j++) {
			if (v[i][j] == 'S') hedgehog.emplace(i, j, 1);
			else if (v[i][j] == '*') water.emplace(i, j, 1);
			else if (v[i][j] == 'D') {
				Dx = i;
				Dy = j;
			}
		}
	}

	bfs_water();

	int cnt = bfs_hedgehog();

	if (cnt == -1) cout << "KAKTUS";
	else cout << cnt - 1;
}