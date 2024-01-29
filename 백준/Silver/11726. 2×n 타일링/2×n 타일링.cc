#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n;
	cin >> n;

	vector<int> dp(1001, 0);
	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= n; i++) {

		// i번째 경우의 수
		// 1. 세로로 세울 때 : 직전 경우의 수에서 블럭 하나만 추가하면 되므로 dp[i - 1]과 같다.
		// 2. 가로로 세울 때 : 가로로 세우기 위해선 2칸이 필요하므로 dp[i - 2]와 같다.
		dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
	}
	cout << dp[n];
}