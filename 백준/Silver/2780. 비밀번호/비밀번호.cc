#include <bits/stdc++.h>
using namespace std;

constexpr int MOD = 1234567;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    vector<vector<int>> dp(1000, vector<int>(10));

    for (int i = 0; i < 10; i++) dp[0][i] = 1;
    for (int i = 1; i < 1000; i++) {
        dp[i][0] = dp[i - 1][7];
        dp[i][1] = (dp[i - 1][2] + dp[i - 1][4]) % MOD;
        dp[i][2] = (dp[i - 1][1] + dp[i - 1][3] + dp[i - 1][5]) % MOD;
        dp[i][3] = (dp[i - 1][2] + dp[i - 1][6]) % MOD;
        dp[i][4] = (dp[i - 1][1] + dp[i - 1][5] + dp[i - 1][7]) % MOD;
        dp[i][5] = (dp[i - 1][2] + dp[i - 1][4] + dp[i - 1][6] + dp[i - 1][8]) % MOD;
        dp[i][6] = (dp[i - 1][3] + dp[i - 1][5] + dp[i - 1][9]) % MOD;
        dp[i][7] = (dp[i - 1][4] + dp[i - 1][8] + dp[i - 1][0]) % MOD;
        dp[i][8] = (dp[i - 1][5] + dp[i - 1][7] + dp[i - 1][9]) % MOD;
        dp[i][9] = (dp[i - 1][6] + dp[i - 1][8]) % MOD;
    }

    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        cout << accumulate(dp[N - 1].begin(), dp[N - 1].end(), 0) % MOD << '\n';
    }
}
