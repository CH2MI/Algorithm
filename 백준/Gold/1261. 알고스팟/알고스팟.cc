#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int N, M;
	cin >> M >> N;
	vector<string> adj(N);
	vector<vector<int>> visited(N, vector<int>(M));

	for (int i = 0; i < N; i++) {
		cin >> adj[i];
	}

	priority_queue<tuple<int, int, int>> pq;

	pq.push({ 0, 0, 0 });

	while (!pq.empty()) {
		auto& [cnt, a, b] = pq.top();
		int x = a;
		int y = b;
		int c = -cnt;
		pq.pop();

		if (x < 0 || y < 0 || x >= N || y >= M) continue;
		if (visited[x][y]) continue;
		if (adj[x][y] == '1') c++;
		if (x == N - 1 && y == M - 1) {
			cout << c;
			break;
		}

		visited[x][y] = 1;

		for (int k = 0; k < 4; k++) {
			int i = x + dx[k];
			int j = y + dy[k];
			pq.push({ -c, i, j });
		}
	}
}