#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> v(n, vector<int>(m));
	vector<vector<int>> result(n, vector<int>(m, 0));
	vector<vector<int>> visited(n, vector<int>(m, 0));
	int x, y;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> v[i][j];
			if (v[i][j] == 2) {
				x = i; y = j;
			}
		}
	}

	queue<pair<pair<int, int>, int>> q;
	q.push({ {x, y}, 0 });
	
	while (!q.empty()) {
		auto t = q.front();
		q.pop();

		// 갈 수 없는 곳은 검사하지 않는다.
		if (v[t.first.first][t.first.second] == 0) continue;

		// 이미 지나온 곳이면 검사하지 않는다.
		if (visited[t.first.first][t.first.second] == 1) continue;

		visited[t.first.first][t.first.second] = 1;
		result[t.first.first][t.first.second] = t.second;

		// 상하좌우를 큐에 넣어준다.
		if (t.first.first > 0) {
			q.push({ {t.first.first - 1, t.first.second}, t.second + 1 });
		}
		if (t.first.first < n - 1) {
			q.push({ {t.first.first + 1, t.first.second}, t.second + 1 });
		}
		if (t.first.second > 0) {
			q.push({ {t.first.first, t.first.second - 1}, t.second + 1 });
		}
		if (t.first.second < m - 1) {
			q.push({ {t.first.first, t.first.second + 1}, t.second + 1 });
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!result[i][j] && v[i][j] == 1)
				cout << "-1 ";
			else
				cout << result[i][j] << ' ';
			
		}
		cout << '\n';
	}
}