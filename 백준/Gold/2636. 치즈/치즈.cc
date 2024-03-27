#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int X[4] = { -1, 1, 0, 0 };
int Y[4] = { 0, 0, -1, 1 };

vector<vector<int>> v;
int N, M;

// 외부 공기를 찾는다.
void bfs(int i, int j) {
	queue<pair<int, int>> q;
	q.emplace(i, j);

	while (!q.empty()) {
		auto t = q.front();
		q.pop();

		if (t.first < 0 || t.first >= N || t.second < 0 || t.second >= M) continue;
		if (v[t.first][t.second] != 0) continue;

		// 외부 공기라고 체크한다.
		v[t.first][t.second] = -1;

		for (int k = 0; k < 4; k++) {
			q.emplace(t.first + X[k], t.second + Y[k]);
		}
	}
}

bool melt(int& count) {
	vector<pair<int, int>> point;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (v[i][j] == 1) {
				int cnt = 0;
				for (int k = 0; k < 4; k++) {
					int x = i + X[k];
					int y = j + Y[k];
					if (x < 0 || x >= N || y < 0 || y >= M) continue;
					if (v[x][y] == -1) cnt++;
				}
				
				// 외부 공기와 맞닿은 치즈는 모두 녹인다.
				if (cnt > 0) point.emplace_back(i, j);
			}
		}
	}

	// 더이상 녹는 지점이 없으면 false를 반환한다.
	if (!point.size()) return false;

	// 치즈를 녹이고 외부공기를 찾는다.
	for (auto i : point) {
		v[i.first][i.second] = 0;
		bfs(i.first, i.second);
	}
	count = point.size();
	return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> N >> M;

	v.assign(N, vector<int>(M, 0));

	for (auto& i : v) {
		for (auto& j : i) {
			cin >> j;
		}
	}

	bfs(0, 0); 

	int days = 0;
	int count = 0;

	while (melt(count)) {
		days++;
	}

	cout << days << '\n' << count;
}	