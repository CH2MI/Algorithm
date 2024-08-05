#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define INF (int)1e9

vector<vector<int>> adj;
vector<int> dp;
int N, P;

int Repair(int repaired, int count) {
	if (count >= P)
		return 0;

	if (dp[repaired] != -1)
		return dp[repaired];

	dp[repaired] = INF;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!(repaired & (1 << i)) || repaired & (1 << j)) continue;
			dp[repaired] = min(Repair(repaired | (1 << j), count + 1) + adj[i][j], dp[repaired]);
		}
	}

	return dp[repaired];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> N;

	adj = vector<vector<int>>(N, vector<int>(N));
	for (auto& i : adj)
		for (auto& j : i)
			cin >> j;

	dp = vector<int>(1 << N, -1);
	
	string s; cin >> s >> P;
	reverse(s.begin(), s.end());
	int count = 0;
	int repaired = 0;
	for (auto c : s) {
		repaired <<= 1;
		repaired |= (c == 'Y' ? 1 : 0);
		count += (c == 'Y' ? 1 : 0);
	}
	
	int ret = Repair(repaired, count);
	if (ret == INF) cout << "-1";
	else cout << ret;
	
}