#include <iostream>
#include <vector>
#include <deque>
#include <tuple>
using namespace std;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int N, M;

void BFS(pair<int, int>& p, vector<vector<char>>& adj, vector<vector<int>>& visited) {
	deque<tuple<int, int, int>> dq;
	dq.push_back({ 0, p.first, p.second });

	while (!dq.empty()) {
		auto [cnt, x, y] = dq.front();
		dq.pop_front();

		for (int k = 0; k < 4; k++) {
			int i = x + dx[k];
			int j = y + dy[k];

			if (i < 0 || i >= N + 2 || j < 0 || j >= M + 2) continue;
			if (visited[i][j] != -1) continue;
			if (adj[i][j] == '*') continue;

			if (adj[i][j] == '#') {
				visited[i][j] = cnt + 1;
				dq.push_back({ cnt + 1, i, j });
			}
			else {
				visited[i][j] = cnt;
				dq.push_front({ cnt, i, j });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int T;
	cin >> T;

	while (T--) {
		pair<int, int> p1({ -1, -1 }), p2, p3({ 0, 0 });
		cin >> N >> M;
		cin.ignore();
		vector<vector<char>> adj1(N + 2, vector<char>(M + 2, '.')), adj2(adj1);
		
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				adj1[i][j] = cin.get();
				if (adj1[i][j] == '$') {
					if (p1.first == -1) p1 = { i, j };
					else p2 = { i, j };
					adj1[i][j] = '.';
				}
				adj2[i][j] = adj1[i][j];
			}
			cin.ignore();
		}

		vector<vector<int>> v1(N + 2, vector<int>(M + 2, -1)), v2(v1), v3(v1);

		BFS(p1, adj1, v1);
		BFS(p2, adj1, v2);
		BFS(p3, adj2, v3);

		int mn = (int)1e9;
		for (int i = 0; i < N + 2; i++) {
			for (int j = 0; j < M + 2; j++) {
				if (adj1[i][j] == '*') continue;
				if (v1[i][j] == -1 || v2[i][j] == -1 || v3[i][j] == -1) continue;

				int m = v1[i][j] + v2[i][j] + v3[i][j];
				if (adj1[i][j] == '#') {
					m -= 2;
				}
				mn = min(mn, m);
			}
		}

		cout << mn << '\n';
	}
}