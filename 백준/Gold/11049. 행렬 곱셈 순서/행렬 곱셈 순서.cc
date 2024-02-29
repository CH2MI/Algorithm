#include <iostream>
#include <climits>
using namespace std;

int dp[501][501][3];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> dp[i][i][0] >> dp[i][i][1];
	}

	/*
		11066번 문제와 같이 i ~ j번째에서의 최솟값은 i ~ n, n + 1 ~ j (i <= n <= j) 로 나누어서 최솟값을 찾는다.
	*/
	for (int i = 2; i <= N; i++) {
		for (int j = 0; j < N - i + 1; j++) {
			int m = INT_MAX;
			int x = 0, y = 0;
			for (int k = 0; k < i - 1; k++) {
				int t = dp[1 + j][1 + j + k][0] * dp[1 + j][1 + j + k][1] * dp[2 + j + k][j + i][1] + dp[1 + j][1 + j + k][2] + dp[2 + j + k][j + i][2];
				if (t < m) {
					x = dp[1 + j][1 + j + k][0];
					y = dp[2 + j + k][j + i][1];
					m = t;
				}
			}
			dp[1 + j][i + j][0] = x;
			dp[1 + j][i + j][1] = y;
			dp[1 + j][i + j][2] = m;

		}
	}
	cout << dp[1][N][2] << '\n';
}