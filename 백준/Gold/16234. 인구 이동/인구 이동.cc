#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int N, L, R;
vector<vector<int>> adj;
vector<pair<int, int>> groups;
vector<vector<int>> visited;

void BFS(int a, int b, int cnt) {
	queue<pair<int, int>> q;
	visited[a][b] = cnt;
	q.push({ a, b });

	while (!q.empty()) {
		auto [x, y] = q.front();
		q.pop();

		groups[cnt].first += adj[x][y];
		groups[cnt].second++;

		for (int k = 0; k < 4; k++) {
			int i = x + dx[k];
			int j = y + dy[k];

			if (i < 0 || i >= N || j < 0 || j >= N) continue;
			if (visited[i][j] != -1) continue;

			int diff = abs(adj[x][y] - adj[i][j]);
			if (L <= diff && diff <= R) {
				visited[i][j] = cnt;
				q.push({ i, j });
			}
				
		}
	}
}

bool Solve() {
	int cnt = 0;
	visited.assign(N, vector<int>(N, -1));
	groups.assign(N * N, { 0, 0 });

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visited[i][j] != -1) continue;
			BFS(i, j, cnt++);
		}
	}

	return cnt != N * N;
}

void move() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			adj[i][j] = groups[visited[i][j]].first / groups[visited[i][j]].second;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N >> L >> R;

	adj.assign(N, vector<int>(N, 0));

	for (auto& i : adj) {
		for (auto& j : i) {
			cin >> j;
		}
	}

	int day = 0;
	while (Solve()) {
		move();
		day++;
	}
	cout << day;
}