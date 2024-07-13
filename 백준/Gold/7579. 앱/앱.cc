#include <iostream>
#include <vector>
#include <algorithm>

// c 최댓값 100, n 최댓값 100
#define MAX 10001
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int N, M;
	cin >> N >> M;
	vector<pair<int, int>> v(N);
	vector<vector<int>> dp(MAX, vector<int>(N));

	for (auto& i : v) cin >> i.second;
	for (auto& i : v) cin >> i.first;

	sort(v.begin(), v.end());

	for (int i = 0; i < MAX; i++) {
		if (i < v[0].first) continue;

		for (int j = 0; j < N; j++) {
			int c = i - v[j].first;

			if (j == 0) dp[i][j] = v[j].second;
			else if (c < 0) dp[i][j] = dp[i][j - 1];
			else dp[i][j] = max(dp[i][j - 1], v[j].second + dp[c][j - 1]);

			if (dp[i][j] >= M) {
				cout << i;
				return 0;
			}
		}
	}
}