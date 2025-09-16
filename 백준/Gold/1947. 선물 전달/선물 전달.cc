#include <bits/stdc++.h>
using namespace std;

constexpr int MAX = 1000000;
constexpr int MOD = 1000000000;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int N; cin >> N;
    vector<long long> dp(MAX);
    dp[0] = 0; dp[1] = 1;

    for (int i = 2; i < MAX; i++) {
        dp[i] = ((dp[i - 1] + dp[i - 2]) % MOD) * i % MOD;
    }

    cout << dp[N - 1];
}
