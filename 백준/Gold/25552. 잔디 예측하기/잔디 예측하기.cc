#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

vector<string> v1, v2;
int N, M;
int dist;

queue<pair<int, int>> q;

bool bfs() {
	while (!q.empty()) {
		auto [i, j] = q.front();
		q.pop();

		// 시작부터 예측된 잔디가 틀렷을 때
		if (v2[i][j] == 'X') return false;

		// 맨해튼 거리가 n이내인 점을 탐색
		for (int x = i - dist; x <= i + dist; x++) {
			for (int y = j - dist; y <= j + dist; y++) {

				// 예측한 잔디가 있는 곳에만 잔디를 퍼트린다.
				if (abs(i - x) + abs(j - y) <= dist) {
					if (x < 0 || x >= N || y < 0 || y >= M) continue;
					if (v1[x][y] == 'O') continue;
					if (v2[x][y] == 'X') continue;

					v1[x][y] = 'O';
					q.emplace(x, y);
				}
			}
		}		
	}

	// 퍼질 수 있는 위치에 모두 퍼졌을 때 두 잔디가 다르면 불가능
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (v1[i][j] != v2[i][j]) return false;
		}
	}

	// 똑같이 퍼졌으니 가능
	return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> N >> M;

	v1.assign(N, string());
	for (int i = 0; i < N; i++) {
		cin >> v1[i];
		for (int j = 0; j < M; j++) {
			if (v1[i][j] == 'O') q.emplace(i, j);
		}
	}

	cin >> dist;

	v2.assign(N, string());
	for (int i = 0; i < N; i++) {
		cin >> v2[i];
	}

	if (bfs()) cout << "YES\n";
	else cout << "NO\n";
}
