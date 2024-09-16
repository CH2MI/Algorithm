#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
using namespace std;

#define INF (int)1e9

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int N, M;
int Tg, Tb;

vector<string> adj;
vector<pair<int, int>> point;
vector<vector<int>> unsafe;

void Dijkstra() {
	priority_queue<tuple<int, int, int>> pq;
	
	for (const auto& i : point) {
		pq.push({ 0, i.first, i.second });
	}

	while (!pq.empty()) {
		auto [t, x, y] = pq.top();
		pq.pop();

		if ((t *= -1) > Tg) continue;
		if (x < 0 || x >= N || y < 0 || y >= M) continue;
		if (unsafe[x][y] != INF) continue;

		if (adj[x][y] == '#') {
			t += Tb;
		}

		unsafe[x][y] = t;

		for (int k = 0; k < 4; k++) {
			int i = dx[k] + x;
			int j = dy[k] + y;

			pq.push({ -(t + 1), i, j });
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int X, B;

	cin >> N >> M >> Tg >> Tb >> X >> B;

	adj.assign(N, string());
	point.reserve(X);
	unsafe.assign(N, vector<int>(M, INF));

	for (int i = 0; i < N; i++) {
		cin >> adj[i];

		for (int j = 0; j < M; j++) {
			if (adj[i][j] == '*') {
				point.push_back({ i, j });
			}
		}
	}

	Dijkstra();

	vector<pair<int, int>> answer;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (unsafe[i][j] > Tg)
				answer.push_back({ i + 1, j + 1 });
		}
	}

	if (!answer.size()) cout << "-1";
	else {
		for (const auto& i : answer)
			cout << i.first << ' ' << i.second << '\n';
	}
}