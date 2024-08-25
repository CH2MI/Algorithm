#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int N;
	cin >> N;

	vector<pair<long long, long long>> dp(N + 1);
	dp[1].second = 1;
	for (int i = 2; i <= N; i++) {
		dp[i].first += dp[i - 1].first + dp[i - 1].second;
		dp[i].second += dp[i - 1].first;
	}
	cout << dp[N].first + dp[N].second;
}