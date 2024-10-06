#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int N, M;

vector<vector<int>> map;
vector<vector<bool>> visited;
vector<vector<pair<int, int>>> adj;
int c = 1;

void Naming(int x, int y) {
	visited[x][y] = true;
	map[x][y] = c;

	for (int k = 0; k < 4; k++) {
		int i = x + dx[k];
		int j = y + dy[k];
		if (i < 0 || i >= N || j < 0 || j >= M) continue;
		if (visited[i][j]) continue;
		if (!map[i][j]) continue;
		Naming(i, j);
	}
}

int make_bridge(int x, int y, int direction, int length, int& end) {
	if (x < 0 || x >= N || y < 0 || y >= M) return 0;
	if (map[x][y] == end) return 0;
	if (map[x][y]) {
		end = map[x][y];
		return length;
	}

	int i = x + dx[direction];
	int j = y + dy[direction];

	return make_bridge(i, j, direction, length + 1, end);
}

int Prim() {
	priority_queue<pair<int, int>> pq;
	vector<bool> v(c);
	int cnt = 0;
	int sum = 0;
	pq.push({ 0, 1 });
	while (!pq.empty()) {
		auto [cur_dist, cur_node] = pq.top();
		pq.pop();
		cur_dist = -cur_dist;

		if (v[cur_node]) continue;
		v[cur_node] = true;
		sum += cur_dist;
		if (++cnt == c - 1) break;

		for (const auto& [nxt_node, nxt_dist] : adj[cur_node]) {
			pq.push({ -nxt_dist, nxt_node });
		}
	}

	if (cnt == c - 1) return sum;
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> M;

	map.assign(N, vector<int>(M));
	visited.assign(N, vector<bool>(M));
	

	for (auto& i : map) {
		for (auto& j : i)
			cin >> j;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visited[i][j] || !map[i][j]) continue;
			Naming(i, j);
			c++;
		}
	}
	adj.assign(c, vector<pair<int, int>>());

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j]) {
				for (int k = 0; k < 4; k++) {
					int end = map[i][j];
					int len = make_bridge(i + dx[k], j + dy[k], k, 1, end);
					if (--len > 1) {
						adj[map[i][j]].push_back({ end, len });
					}
				}
			}
		}
	}

	cout << Prim();
}