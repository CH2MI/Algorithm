#include <iostream>
#include <vector>
#include <string>
using namespace std;

string s;
vector<vector<bool>> v;

bool Is_Palindrome(int i, int j) {
	int x = i + 1;
	int y = j - 1;

	return ((s[i] == s[j]) && (x >= y || v[x][y]));
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> s;
	int N = s.size();
	v = vector<vector<bool>>(N, vector<bool>(N));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - i; j++) {
			if (!i) v[j][j] = true;
			else {
				v[j][j + i] = Is_Palindrome(j, j + i);
			}
		}
	}
	

	vector<int> dp(N + 1, 1e9);
	dp[0] = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = i; j > 0; j--) {

			if (v[j - 1][i - 1])

				// j ~ i가 회문이면 j - 1번째까지 분할 개수와 현재 팰린드롬을 합한 값과, 기존 i까지의 최솟값을 비교한다.
				dp[i] = min(dp[j - 1] + 1, dp[i]);
		}
	}

	cout << dp[N];
}