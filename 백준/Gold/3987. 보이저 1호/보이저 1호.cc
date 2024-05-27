#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

typedef tuple<int, int, int, int> ti;

int N, M, R, C;
vector<string> adj;
vector<vector<ti>> visited;

pair<int, int> GetDelta(int direction) {
	int dx = 0, dy = 0;
	if (direction == 0) dx = -1;
	else if (direction == 1) dy = 1;
	else if (direction == 2) dx = 1;
	else if (direction == 3) dy = -1;
	return { dx, dy };
}

bool isVisited(int i, int j, int direction) {
	if (direction == 0 && get<0>(visited[i][j])) return true;
	else if (direction == 1 && get<1>(visited[i][j])) return true;
	else if (direction == 2 && get<2>(visited[i][j])) return true;
	else if (direction == 3 && get<3>(visited[i][j])) return true;
	return false;
}

void SetVisited(int i, int j, int direction) {
	if (direction == 0) get<0>(visited[i][j]) = 1;
	else if (direction == 1)  get<1>(visited[i][j]) = 1;
	else if (direction == 2) get<2>(visited[i][j]) = 1;
	else if (direction == 3) get<3>(visited[i][j]) = 1;
}

int bfs(int direction) {
	queue<tuple<int, int, int>> q;
	q.emplace(R - 1, C - 1, 0);

	while (!q.empty()) {
		auto [i, j, cnt] = q.front();
		q.pop();

		// 항성계를 벗어났을 때
		if (i < 0 || i >= N || j < 0 || j >= M) return cnt;

		// 무한히 전파될 때
		if (isVisited(i, j, direction)) return -1;

		// 블랙홀을 만났을 때
		if (adj[i][j] == 'C') return cnt;

		// 방문처리
		SetVisited(i, j, direction);

		// 반사
		if (adj[i][j] == '\\') {
			direction ^= 3;
		}
		else if (adj[i][j] == '/') {
			direction ^= 1;
		}

		auto [dx, dy] = GetDelta(direction);
		q.emplace(i + dx, j + dy, cnt + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	
	cin >> N >> M;

	adj.assign(N, string());
	
	for (int i = 0; i < N; i++) {
		cin >> adj[i];
	}

	cin >> R >> C;

	int ret = -2;
	char c;
	char data[] = { 'U', 'R', 'D', 'L' };
	for (int i = 0; i < 4; i++) {
		visited.assign(N, vector<ti>(M, ti()));
		int t = bfs(i);
		if (ret != -1 && (t == -1 || t > ret)) {
			c = data[i];
			ret = t;
		}
	}

	cout << c << '\n';
	if (ret == -1) cout << "Voyager";
	else cout << ret;
}