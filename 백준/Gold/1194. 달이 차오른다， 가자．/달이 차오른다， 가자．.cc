#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <climits>
using namespace std;

int N, M;
vector<string> adj;
vector<vector<vector<bool>>> visited;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = { 0, 0, -1, 1 };

int BFS(pair<int, int> start) {
	queue<tuple<int, int, int, int>> q;
	q.emplace(0, 0, start.first, start.second);

	while (!q.empty()) {
		auto [cnt, keys, x, y] = q.front();
		q.pop();

		if (x < 0 || x >= N || y < 0 || y >= M) continue;
		if (adj[x][y] == '#') continue;
		if (visited[x][y][keys]) continue;

		if (adj[x][y] == '1') return cnt;

		// 열쇠를 찾았을 때 열쇠를 추가한다.
		if (adj[x][y] >= 'a') {
			keys |= 1 << (adj[x][y] - 'a');
		}
		
		// 문을 찾았을 때
		else if (adj[x][y] >= 'A') {

			// 열쇠가 없으면 지나가지 못한다.
			if (!(keys & (1 << (adj[x][y] - 'A')))) continue;
		}

		visited[x][y][keys] = true;

		for (int k = 0; k < 4; k++) {	
			int i = x + dx[k];
			int j = y + dy[k];
			q.emplace(cnt + 1, keys, i, j);
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> N >> M;
	adj = vector<string>(N);
	visited.assign(N, vector<vector<bool>>(M, vector<bool>(1 << 6, false)));

	pair<int, int> start;

	for (int i = 0; i < N; i++) {
		cin >> adj[i];
		for (int j = 0; j < M; j++) {
			if (adj[i][j] == '0')
				start = { i, j };
		}
	}

	cout << BFS(start);
}