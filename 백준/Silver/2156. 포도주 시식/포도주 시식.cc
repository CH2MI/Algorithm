#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	int dp[10001][5] = { 0, };
	int arr[10001] = { 0, };
	for (int i = 1; i <= n; i++) cin >> arr[i];
	// 1: i-2 i-1 2: i-2 i 3: i-1 i 4: i-3 i
	dp[1][0] = dp[1][2] = dp[1][3] = dp[1][4] = arr[1];
	if (n > 1) {
		dp[2][1] = arr[1];
		dp[2][2] = dp[2][4] = arr[2];
		dp[2][3] = arr[1] + arr[2];
		dp[2][0] = max({ dp[2][1], dp[2][2], dp[2][3], dp[2][4] });
	}
	for (int i = 3; i <= n; i++) {
		dp[i][1] = max(dp[i - 2][2], dp[i - 2][4]) + arr[i - 1];
		dp[i][2] = max({ dp[i - 2][2], dp[i - 2][3], dp[i - 2][4] }) + arr[i];
		dp[i][3] = max(dp[i - 1][2], dp[i - 1][4]) + arr[i];
		dp[i][4] = max({ dp[i - 3][2], dp[i - 3][3], dp[i - 3][4] }) + arr[i];
		dp[i][0] = max({ dp[i][1], dp[i][2], dp[i][3], dp[i][4] });
	}
	cout << dp[n][0];
} 