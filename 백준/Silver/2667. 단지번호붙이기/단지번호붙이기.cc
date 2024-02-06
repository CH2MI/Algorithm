#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int>> v;
vector<vector<int>> visited;

int bfs(int x, int y, int N) {
	queue<pair<int, int>> q;
	q.push({ x, y });
	int cnt = 0;

	while (!q.empty()) {
		auto t = q.front();
		q.pop();

		if (t.first < 0 || t.second < 0 || t.first >= N || t.second >= N) continue;
		if (v[t.first][t.second] == 0) continue;
		if (visited[t.first][t.second]) continue;

		visited[t.first][t.second] = 1;
		++cnt;

		q.push({ t.first - 1, t.second });
		q.push({ t.first + 1, t.second });
		q.push({ t.first, t.second - 1 });
		q.push({ t.first, t.second + 1 });
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int N;
	cin >> N;
	v.assign(N, vector<int>(N));
	visited.assign(N, vector<int>(N));
	vector<int> c;
	cin.ignore();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			v[i][j] = cin.get() - '0';
		}
		cin.ignore();
	}

	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {

			// 탐색하지 않은 곳을 찾을 때 마다 횟수와 해당 단지 내 집의 수를 카운트 한다.
			if (v[i][j] == 1 && visited[i][j] == 0) {
				cnt++;
				c.push_back(bfs(i, j, N));
			}
		}
	}

	sort(c.begin(), c.end());

	cout << cnt << '\n';
	for (auto i : c) {
		cout << i << '\n';
	}
}