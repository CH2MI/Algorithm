#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int T;
	cin >> T;
	for (int test_case = 0; test_case < T; ++test_case) {
		int N;
		cin >> N;

		vector<int> v(N), S(N + 1);
		for (auto& i : v) {
			cin >> i;
		}

		S[0] = 0;
		for (int i = 1; i <= N; i++) {
			S[i] = S[i - 1] + v[i - 1];
		}

		vector<vector<int>> dp(N + 1, vector<int>(N + 1));

		// 모든 파일을 합치는 것의 최솟값ㅇ은 [1, 2 + 3 + ... + n] [ 1 + 2, 3 + 4 + ... + N] ... [1 + 2 + ... + N - 1, 1] 에서의 최솟값이다
		// [1, 2 + 3 + ... + n]에서 뒷 부분은 [2, 3 + 4 + ... n], [2 + 3, 4 + 5 + ... + n] 에서의 최솟값이다.
		// 해당 부분을 모두 메모제이션하면서 계산하면 모든 파일을 합치는데 필요한 최솟값을 알 수 있다.
		for (int i = 2; i <= N; i++) {
			for (int j = 0; j < N - i + 1; j++) {
				int m = 1 << 30;
				for (int k = 0; k < i - 1; k++) {
					m = min(m, dp[1 + j][1 + j + k] + dp[2 + j + k][j + i]);
				}

				dp[1 + j][i + j] = m + (S[j + i] - S[j]);
			}
		}
		cout << dp[1][N] << '\n';
	}
}