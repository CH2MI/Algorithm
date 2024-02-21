#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; ++test_case) {

		int N;
		cin >> N;

		vector<vector<int>> arr(N, vector<int>(2));
		
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < N; j++) {
				cin >> arr[j][i];
			}
		}

		vector<vector<int>> dp(N, vector<int>(2));
		dp[0][0] = arr[0][0];
		dp[0][1] = arr[0][1];

		if (N > 1) {
			dp[1][0] = arr[1][0] + dp[0][1];
			dp[1][1] = arr[1][1] + dp[0][0];
		}

		for (int i = 2; i < N; i++) {

			// 해당 스티커를 선택했을 때 직전 라인의 대각선 스티커를 선택하거나 
			// 2번째 전 라인의 대각선 스티커를 선택해야한다.
			dp[i][0] = arr[i][0] + max( dp[i - 1][1], dp[i - 2][1] );
			dp[i][1] = arr[i][1] + max( dp[i - 1][0], dp[i - 2][0] );
		}
		cout << max(dp[N - 1][0], dp[N - 1][1]) << '\n';
	}
}