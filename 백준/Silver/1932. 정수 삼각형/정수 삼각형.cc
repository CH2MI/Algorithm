#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;
	int** dp = new int* [N];
	dp[0] = new int[1];
	cin >> dp[0][0];
	int m = dp[0][0];
	for (int i = 1; i < N; i++) {
		dp[i] = new int[i + 1];
		for (int j = 0; j < i + 1; j++) {
			int t;
			cin >> t;
			if (j == 0) dp[i][j] = dp[i - 1][j] + t;
			else if (j == i) dp[i][j] = dp[i - 1][j - 1] + t;
			else dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + t;
			if (dp[i][j] > m) m = dp[i][j];
		}
	}
	cout << m;
}