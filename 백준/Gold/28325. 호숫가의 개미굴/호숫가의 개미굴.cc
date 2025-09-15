#include <bits/stdc++.h>
using namespace std;

constexpr int MOD = 1000000;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int N; cin >> N;
    vector<long long> v(N);
    for (auto& i : v) cin >> i;

    vector<array<long long, 4>> dp(N);
    dp[0][0] = 1, dp[0][1] = v[0];
    for (int i = 1; i < N; i++) {
        dp[i][0] = dp[i - 1][1] + 1;
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]) + v[i];
        dp[i][2] = dp[i - 1][3] + 1;
        dp[i][3] = max(dp[i - 1][2], dp[i - 1][3]) + v[i];
    }

    cout << max(max(dp[N - 2][0], dp[N - 2][1]) + v.back(), max(dp[N - 1][2], dp[N - 1][3]) + v.front());
}