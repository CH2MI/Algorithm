#include <iostream>
#include <vector>
#define INF (int)1e9
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n, t, m, s, e;
	cin >> n >> t >> m >> s >> e;

	vector<vector<int>> dp(n, vector<int>(t + 1, INF));

	dp[s][0] = 0;

	for (int k = 0; k < t; k++) {
		for (int i = 0; i < n; i++) dp[i][k + 1] = dp[i][k];

		for (int i = 0; i < m; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			dp[a][k + 1] = min(dp[a][k + 1], dp[b][k] + c );
			dp[b][k + 1] = min(dp[b][k + 1], dp[a][k] + c );
		}
	}

	if (dp[e][t] == INF) cout << -1;
	else cout << dp[e][t];
}