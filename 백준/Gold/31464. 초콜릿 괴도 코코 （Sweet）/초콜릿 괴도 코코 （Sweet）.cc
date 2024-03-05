#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// 위, 아래, 왼쪽, 오른쪽
int X[4] = { -1, 1, 0, 0 };
int Y[4] = { 0, 0, -1, 1 };

int N;
vector<string> v;
vector<vector<bool>> visited;

int M = 0;
int I, J;

// 사이클이 생기는 지 확인
bool dfs(int i, int j, int pi, int pj, int& cnt) {
	visited[i][j] = 1;
	++cnt;
	for (int k = 0; k < 4; k++) {
		int x = i + X[k];
		int y = j + Y[k];
		if (x < 0 || x >= N || y < 0 || y >= N) continue;
		if (x == pi && y == pj) continue;
		if (v[x][y] == '.') continue;
		// 사이클이 생겼다.
		if (visited[x][y]) return false;

		if (!dfs(x, y, i, j, cnt)) return false;
	}
	return true;
}

void setDefaultPoint() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (v[i][j] == '#') {
				I = i;
				J = j;
				return;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> N;
	cin.ignore();
	v.assign(N, string());
	for (int i = 0; i < N; i++) {
		getline(cin, v[i]);
		M += count(v[i].begin(), v[i].end(), '#');
	}
	setDefaultPoint();
	vector<pair<int, int>> result;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (v[i][j] == '.') continue;

			// 해당 초콜릿을 먹는다.
			v[i][j] = '.';

			if (i == I && j == J) setDefaultPoint();
			int cnt = 0;
			visited.assign(N, vector<bool>(N, 0));

			if (dfs(I, J, -1, -1, cnt)) {
				if (cnt == M - 1) result.emplace_back(i, j);
			}

			v[i][j] = '#';
		}
	}
	cout << result.size() << '\n';
	for (auto i : result) {
		cout << i.first + 1 << ' ' << i.second + 1 << '\n';
	}
	


}