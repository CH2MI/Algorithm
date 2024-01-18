#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int N;
	cin >> N;

	int* dp = new int[N + 1]();
	dp[1] = 0;
	if (N > 1) dp[2] = 1;
	if (N > 2) dp[3] = 1;
	for (int i = 4; i <= N; i++) {
		int a = 100000000, b = 100000000, c = dp[i - 1];
		if (i % 3 == 0) {
			a = dp[i / 3];
		}
		if (i % 2 == 0) {
			b = dp[i / 2];
		}
		dp[i] = min({ a, b, c }) + 1;
	}

	cout << dp[N];
	delete[] dp;
}