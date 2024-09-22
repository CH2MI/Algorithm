#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int dx[5] = { 0, 1, 0, -1, 0 };
int dy[5] = { 1, 0, -1, 0, 0 };

int N, M;
int Sx, Sy, Ex, Ey;

vector<string> adj;
vector<vector<int>> adj2;
vector<pair<int, int>> ghost;
vector<vector<vector<bool>>> visited;


void Ghost() {
	for (const auto& g : ghost) {
		int i = adj[g.first][g.second] - '0';
		adj[g.first][g.second] = '#';
		for (int j = 0; j < 4; j++) {
			int k = (i + j) % 4;
			queue<pair<int, int>> q;
			q.push({ g.first + dx[k], g.second + dy[k] });

			while (!q.empty()) {
				auto [x, y] = q.front();
				q.pop();

				if (x < 0 || x >= N || y < 0 || y >= M) continue;
				if (adj[x][y] != '.') continue;

				adj2[x][y] |= 1 << j;
				q.push({ x + dx[k], y + dy[k] });
			}
		}
	}
}

int Dijkstra() {
	visited.assign(N, vector<vector<bool>>(M, vector<bool>(4, 0)));
	priority_queue<tuple<int, int, int>> pq;
	pq.emplace(0, Sx, Sy);
	while (!pq.empty()) {
		auto [cnt, x, y] = pq.top();
		pq.pop();
		cnt *= -1;

		if (x < 0 || x >= N || y < 0 || y >= M) continue;
		if (adj[x][y] != '.') continue;

		int z = cnt % 4;
		if (adj2[x][y] & (1 << z)) continue;
		if (visited[x][y][z]) continue;

		if (x == Ex && y == Ey) return cnt;

		visited[x][y][z] = true;

		for (int k = 0; k < 5; k++) {
			int i = x + dx[k];
			int j = y + dy[k];
			pq.emplace(-(cnt + 1), i, j);
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> N >> M >> Sx >> Sy >> Ex >> Ey;

	Sx--; Sy--; Ex--; Ey--;

	adj.assign(N, string());
	adj2.assign(N, vector<int>(M, 0));
	ghost.reserve(400);

	for (int i = 0; i < N; i++) {
		cin >> adj[i];

		for (int j = 0; j < M; j++) {
			if ('0' <= adj[i][j] && adj[i][j] <= '3') {
				ghost.push_back({ i, j });
			}
		}
	}

	Ghost();
	int ret = Dijkstra();
	if (ret == -1) cout << "GG";
	else cout << ret;
}