#include <iostream>
#include <vector>
using namespace std;

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

vector<vector<int>> v, dp;
int N, M;

int dfs(int x, int y) {
	if (x == M - 1 && y == N - 1) return 1;
	if (dp[y][x] == -1) {
		dp[y][x] = 0;

		for (int k = 0; k < 4; k++) {
			int i = x + dx[k];
			int j = y + dy[k];

			if (i < 0 || j < 0 || i >= M || j >= N) continue;
			if (v[y][x] <= v[j][i]) continue;
			dp[y][x] += dfs(i, j);
		}

	}
	return dp[y][x];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	
	cin >> N >> M;

	v.assign(N, vector<int>(M, 0));
	dp.assign(N, vector<int>(M, -1));

	for (auto& i : v) {
		for (auto& j : i) {
			cin >> j;
		}
	}
	cout << dfs(0, 0);

}