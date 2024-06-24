#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	vector<vector<int>> v;
	int N, M;
	cin >> N >> M;

	v.assign(N, vector<int>(N, -1));
	
	int dindex = 0;
	int value = N * N;
	int rx, ry;
	queue<pair<int, int>> q;
	q.push({ 0, 0 });

	while (!q.empty()) {
		auto& [i, j] = q.front();
		q.pop();

		if (value == M) {
			rx = i + 1;
			ry = j + 1;
		}

		v[i][j] = value--;

		int fi = i, fj = j;

		// 새롭게 탐색할 수 있는지 확인한다.
		for (int k = 0; k < 4; k++) {
			int ti = i + dx[dindex];
			int tj = j + dy[dindex];

			// 이동할 수 있는 조건이 충족하면 좌표를 갱신한다.
			if (ti >= 0 && tj >= 0 && ti < N && tj < N && v[ti][tj] == -1) {
				i = ti;
				j = tj;
				break;
			}
			
			// 해당 방향으로 진행할 수 없으면 다른 방향을 찾아본다.
			dindex = (dindex + 1) % 4;
		}

		// 이동할 수 있는 위치가 없으면 전부 다 탐색한 것이다.
		if (fi == i && fj == j) break;

		q.push({ i, j });
	}

	for (auto& i : v) {
		for (auto j : i) {
			cout << j << ' ';
		}
		cout << '\n';
	}
	cout << rx << ' ' << ry;
}