#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj;
vector<vector<int>> dp;

void DFS(int p, int n) {
	dp[n][1] = 1;

	for (const auto& i : adj[n]) {
		if (p == i) continue;
		DFS(n, i);
		
		// 내가 얼리어답터라면 자식은 머든 상관 없다.
		dp[n][1] += min(dp[i][0], dp[i][1]);

		// 내가 아니면 자식은 얼리어답터
		dp[n][0] += dp[i][1];
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N; cin >> N;
	adj.assign(N, vector<int>());
	dp.assign(N, vector<int>(2, 0));

	for (int i = 0; i < N - 1; i++) {
		int u, v;
		cin >> u >> v;
		adj[u - 1].push_back(v - 1);
		adj[v - 1].push_back(u - 1);
	}

	DFS(-1, 0);

	cout << min(dp[0][0], dp[0][1]);
}