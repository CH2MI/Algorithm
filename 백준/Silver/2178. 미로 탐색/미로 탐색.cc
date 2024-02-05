#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int N, M;
	cin >> N >> M;
	vector<vector<int>> v(N, vector<int>(M));
	vector<vector<int>> visited(N, vector<int>(M));

	cin.ignore();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			v[i][j] = cin.get() - '0';
		}
		cin.ignore();
	}

	queue<pair<pair<int, int>, int>> q;
	q.push({ {0, 0}, 1 });

	while (!q.empty()) {
		auto t = q.front();
		q.pop();

		// 범위를 벗어난 곳은 건너 뛴다.
		if (t.first.first < 0 || t.first.first >= N || t.first.second < 0 || t.first.second >= M) continue;

		// 갈 수 없는 곳은 건너 뛴다.
		if (v[t.first.first][t.first.second] == 0) continue;

		// 지나온 곳은 건너 뛴다.
		if (visited[t.first.first][t.first.second] == 1) continue;

		// 도착점에 도달하면 종료한다.
		if (t.first.first == N - 1 && t.first.second == M - 1) {
			cout << t.second;
			break;
		}

		visited[t.first.first][t.first.second] = 1;

		q.push({ {t.first.first - 1, t.first.second}, t.second + 1 });
		q.push({ {t.first.first + 1, t.first.second}, t.second + 1 });
		q.push({ {t.first.first, t.first.second - 1}, t.second + 1 });
		q.push({ {t.first.first, t.first.second + 1}, t.second + 1 });
	}
}