#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v, trace;
vector<vector<int>> adj, dp;


void DFS(int p, int n) {
	dp[n][1] = v[n];

	for (const auto& i : adj[n]) {
		if (i == p) continue;
		DFS(n, i);

		dp[n][0] += max(dp[i][0], dp[i][1]);
		dp[n][1] += dp[i][0];
	}
}

void Trace(int p, int n, bool f) {
	if (f) {
		trace.push_back(n);
		for (auto i : adj[n]) {
			if (i == p) continue;
			Trace(n, i, !f);
		}
	}
	else {
		for (auto i : adj[n]) {
			if (i == p) continue;
			if (dp[i][0] <= dp[i][1]) Trace(n, i, !f);
			else Trace(n, i, f);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n; cin >> n;
	
	v.assign(n, 0);
	adj.assign(n, vector<int>());
	dp.assign(n, vector<int>(2));

	for (auto& i : v) cin >> i;

	for (int i = 0; i < n - 1; i++) {
		int s, e;
		cin >> s >> e;
		adj[s - 1].push_back(e - 1);
		adj[e - 1].push_back(s - 1);
	}

	DFS(-1, 0);
	Trace(-1, 0, dp[0][0] <= dp[0][1]);
	cout << max(dp[0][0], dp[0][1]) << '\n';
	
	sort(trace.begin(), trace.end());

	for (const auto& i : trace) cout << i + 1 << ' ';
	
}