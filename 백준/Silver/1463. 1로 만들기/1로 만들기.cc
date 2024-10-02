#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int X; cin >> X;

	vector<int> dp(X + 1);
	dp[2] = 1; dp[3] = 1;
	
	for (int i = 4; i <= X; i++) {
		int mn = dp[i - 1];
		if (i % 2 == 0) mn = min(mn, dp[i / 2]);
		if (i % 3 == 0) mn = min(mn, dp[i / 3]);
		dp[i] = mn + 1;
	}
	cout << dp[X];
}