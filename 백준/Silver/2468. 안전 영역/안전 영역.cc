#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> arr;
vector<vector<int>> visited;

void bfs(int x, int y, int k) {
	queue<pair<int, int>> q;
	int N = arr.size();
	q.push({ x, y });

	while (!q.empty()) {
		auto t = q.front();
		q.pop();

		if (t.first < 0 || t.first >= N || t.second < 0 || t.second >= N) continue;
		if (visited[t.first][t.second]) continue;
		if (arr[t.first][t.second] <= k) continue;

		visited[t.first][t.second] = 1;

		q.push({ t.first - 1, t.second });
		q.push({ t.first, t.second - 1 });
		q.push({ t.first + 1, t.second });
		q.push({ t.first, t.second + 1 });
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int N;
	cin >> N;
	arr.assign(N, vector<int>(N));
	

	int Max = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			if (Max < arr[i][j]) Max = arr[i][j];
		}
	}

	int cnt = 0;
	for (int k = 0; k < Max; k++) {
		visited.assign(N, vector<int>(N));
		int c = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!visited[i][j] && arr[i][j] > k) {
					++c;
					bfs(i, j, k);
				}
			}
		}
		if (cnt < c) cnt = c;
	}
	cout << cnt;
}
