#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
vector<vector<bool>> dp;

bool Is_Palindrome(int i, int j) {
	int x = i + 1;
	int y = j - 1;

	return ((v[i] == v[j]) && (x >= y || dp[x][y]));
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int N; cin >> N;
	
	v = vector<int>(N);
	for (auto& i : v) cin >> i;

	 dp = vector<vector<bool>>(N, vector<bool>(N));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - i; j++) {
			if (!i) dp[j][j] = true;
			else dp[j][j + i] = Is_Palindrome(j, j + i);
		}
	}

	int T; cin >> T;

	while (T--) {
		int s, e;
		cin >> s >> e;
		cout << dp[s - 1][e - 1] << '\n';
	}
}