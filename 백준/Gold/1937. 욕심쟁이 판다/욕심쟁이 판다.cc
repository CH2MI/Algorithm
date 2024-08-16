#include <iostream>
#include <vector>
using namespace std;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

vector<vector<int>> adj;
vector<vector<vector<int>>> dp;
int n;



int DFS(int x, int y) {

	int mx = 0;
	for (int k = 0; k < 4; k++) {
		int i = x + dx[k];
		int j = y + dy[k];

		if (i < 0 || i >= n || j < 0 || j >= n) continue;

		// 기존에 가지 않았던 길
		if (dp[x][y][k] == -1) {
			dp[x][y][k] = 0;

			// 새롭게 갈 수 있으면 탐색한다.
			if (adj[x][y] < adj[i][j])
				dp[x][y][k] = DFS(i, j);
		}
		mx = max(mx, dp[x][y][k]);
	}

	return mx + 1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n;
	adj.assign(n, vector<int>(n, 0));
	dp.assign(n, vector<vector<int>>(n, vector<int>(4, -1)));

	for (auto& i : adj)
		for (auto& j : i)
			cin >> j;

	int mx = 0;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			mx = max(mx, DFS(i, j));

	cout << mx;
}