#include <bits/stdc++.h>
using namespace std;

constexpr int MOD = 1000000;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int N; cin >> N;
    vector dp(N, vector(2, vector<int>(3)));
    dp[0][0][0] = 1, dp[0][1][0] = 1, dp[0][0][1] = 1;

    for (int i = 1; i < N; i++) {
        dp[i][0][0] = (dp[i - 1][0][0] + dp[i - 1][0][1] + dp[i - 1][0][2]) % MOD;
        dp[i][0][1] = dp[i - 1][0][0];
        dp[i][0][2] = dp[i - 1][0][1];
        dp[i][1][0] = (dp[i - 1][0][0] + dp[i - 1][0][1] + dp[i - 1][0][2] + dp[i - 1][1][0] + dp[i - 1][1][1] + dp[i - 1][1][2]) % MOD;
        dp[i][1][1] = dp[i - 1][1][0];
        dp[i][1][2] = dp[i - 1][1][1];
    }

    cout << (dp[N - 1][0][0] + dp[N - 1][0][1] + dp[N - 1][0][2] + dp[N - 1][1][0] + dp[N - 1][1][1] + dp[N - 1][1][2]) % MOD;

}