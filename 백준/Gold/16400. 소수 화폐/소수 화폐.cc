#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N; cin >> N;
	vector<bool> check(N + 1, false);
	vector<int> prime;

	for (int i = 2; i <= N; i++) {
		if (check[i]) continue;
		prime.push_back(i);
        
		for (int j = i + i; j <= N; j += i) {
			check[j] = true;
		}
	}

	vector<int> dp(N + 1);
	dp[0] = 1;

	for (int i = 0; i < (int)prime.size(); i++) {
		for (int j = prime[i]; j <= N; j++) {
			dp[j] = (dp[j] + dp[j - prime[i]]) % 123456789;
		}
	}

	cout << dp[N];
}