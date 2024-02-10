#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int M, N, H;
	cin >> M >> N >> H;
	vector<vector<vector<int>>> arr(H, vector<vector<int>>(N, vector<int>(M)));
	vector<vector<vector<int>>> visited(H, vector<vector<int>>(N, vector<int>(M, -1)));

	queue<pair<tuple<int, int, int>, int>> q;

	// 모든 토마토가 익었는지 
	int cnt = 0;

	// 총 며칠 걸렸는지 판별
	int day = 0;

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				cin >> arr[i][j][k];
				if (arr[i][j][k] == 0) cnt++;
				else if (arr[i][j][k] == 1) {
					q.push({ {i, j, k}, 0 });
					cnt++;
				}
			}
		}
	}

	while (!q.empty()) {
		auto t = q.front();
		q.pop();

		int x = get<0>(t.first);
		int y = get<1>(t.first);
		int z = get<2>(t.first);

		// 범위를 벗어났을 때
		if (x < 0 || x >= H || y < 0 || y >= N || z < 0 || z >= M)
			continue;

		// 토마토가 없을 때
		if (arr[x][y][z] == -1)
			continue;

		// 이미 토마토가 익었을 때
		if (visited[x][y][z] > -1)
			continue;

		visited[x][y][z] = t.second;
		cnt--;
		day = max(t.second, day);

		// 상하좌우앞뒤 6방향을 큐에 넣는다.
		q.push({ {x + 1, y, z}, t.second + 1 });
		q.push({ {x - 1, y, z}, t.second + 1 });
		q.push({ {x, y + 1, z}, t.second + 1 });
		q.push({ {x, y - 1, z}, t.second + 1 });
		q.push({ {x, y, z + 1}, t.second + 1 });
		q.push({ {x, y, z - 1}, t.second + 1 });
	}

	if (cnt != 0) cout << "-1\n";
	else cout << day << '\n';
}
