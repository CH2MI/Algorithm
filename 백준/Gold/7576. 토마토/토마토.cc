#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	int M, N;
	cin >> M >> N;
	vector<vector<int>> v(N, vector<int>(M));
	vector<vector<int>> visited(N, vector<int>(M, 0));
	queue<pair<pair<int, int>, int>> q;
	int c = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> v[i][j];

			// 토마토가 익은 곳은 큐에 넣어준다.
			if (v[i][j] == 1) q.push({ {i, j}, 0 });

			// 토마토가 없는 곳을 카운트 해준다.
			if (v[i][j] == -1) c++;
		}
	}


	int cnt = 0;
	while (!q.empty()) {
		auto t = q.front();
		q.pop();
		
		// 토마토가 없으면 검사하지 않는다.
		if (v[t.first.first][t.first.second] == -1) continue;

		// 이미 지나온 곳이면 검사하지 않는다.
		if (visited[t.first.first][t.first.second] == 1) continue;

		visited[t.first.first][t.first.second] = 1;		
		if (cnt < t.second) cnt = t.second;

		// 상하좌우를 큐에 넣어준다.
		if (t.first.first > 0) {
			if (!visited[t.first.first - 1][t.first.second] && v[t.first.first - 1][t.first.second] == 0) {
				v[t.first.first - 1][t.first.second] = 1;
				q.push({ {t.first.first - 1, t.first.second}, t.second + 1 });
			}
		}
		if (t.first.first < N - 1) {
			if (!visited[t.first.first + 1][t.first.second] && v[t.first.first + 1][t.first.second] == 0) {
				v[t.first.first + 1][t.first.second] = 1;
				q.push({ {t.first.first + 1, t.first.second}, t.second + 1 });
			}
		}
		if (t.first.second > 0) {
			if (!visited[t.first.first][t.first.second - 1] && v[t.first.first][t.first.second - 1] == 0) {
				v[t.first.first][t.first.second - 1] = 1;
				q.push({ {t.first.first, t.first.second - 1}, t.second + 1 });
			}
		}
		if (t.first.second < M - 1) {
			if (!visited[t.first.first][t.first.second + 1] && v[t.first.first][t.first.second + 1] == 0) {
				v[t.first.first][t.first.second + 1] = 1;
				q.push({ {t.first.first, t.first.second + 1}, t.second + 1 });
			}
		}
	}

	// 배열을 모두 더했을 때 모든 곳에 0인 곳이 존재하지 않으면 익는데 걸린 시간을 출력한다.
	int sum = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			sum += v[i][j];
		}
	}
	if (M * N - 2 * c == sum) cout << cnt;
	else cout << "-1";
}