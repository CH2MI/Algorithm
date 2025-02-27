#include <bits/stdc++.h>
using namespace std;

constexpr int MOD = (int)1e9 + 3;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N, K;
    cin >> N >> K;
    vector dp(N, vector(K + 1, 0));;

    for (int i = 0; i < N; i++) {
        dp[i][0] = 1;
        dp[i][1] = i;
    }

    for (int i = 2; i < N; i++) {
        for (int j = 2; j <= K; j++) {
            dp[i][j] = (dp[i - 2][j - 1] + dp[i - 1][j]) % MOD;
        }
    }

    cout << (dp[N - 3][K - 1] + dp[N - 1][K]) % MOD;

}
