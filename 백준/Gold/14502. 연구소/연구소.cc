#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj;
int N, M;
int m = 0;

int X[4] = { 0, 0, -1, 1 };
int Y[4] = { -1, 1, 0, 0 };
 
bool is_blank(int k) {
	int i = k / M;
	int j = k % M;
	if (!adj[i][j]) return true;
	return false;
}

void paint(int k, int mode) {
	int i = k / M;
	int j = k % M;
	adj[i][j] = mode;
}

void dfs(vector<vector<int>>& v, int i, int j) {
	v[i][j] = 2;

	for (int k = 0; k < 4; k++) {
		int x = i + X[k];
		int y = j + Y[k];
		if (x < 0 || x >= N || y < 0 || y >= M) continue;
		if (!v[x][y]) dfs(v, x, y);
	}
}

int count_SafetyZone(vector<vector<int>>& v) {
	int count = 0;
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < M; j++) 
			if (!v[i][j]) ++count;
		
	return count;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> N >> M;
	adj.assign(N, vector<int>(M));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> adj[i][j];
		}
	}

	// 임의의 세 점을 고른다.
	int l = N * M;
	for (int i = 0; i < l - 2; i++) {
		if (!is_blank(i)) continue;
		paint(i, 1);

		for (int j = i + 1; j < l - 1; j++) {
			if (!is_blank(j)) continue;
			paint(j, 1);

			for (int k = j + 1; k < l; k++) {
				if (!is_blank(k)) continue;
				paint(k, 1);

				vector<vector<int>> visited = adj;
				vector<pair<int, int>> list;

				// 현재 바이러스가 있는 곳을 저장한다.
				for (int c = 0; c < l; c++) {
					int x = c / M;
					int y = c % M;
					
					if (visited[x][y] == 2) list.emplace_back(x, y);
				}

				// 바이러스가 있는 곳을 기준으로 dfs를 한다.
				for (auto i : list) {
					dfs(visited, i.first, i.second);
				}

				// 안전구역의 갯수를 세서 갱신한다.
				m = max(m, count_SafetyZone(visited));

				paint(k, 0);
			}
			paint(j, 0);
		}
		paint(i, 0);
	}
	cout << m;
}