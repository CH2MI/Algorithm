#include <bits/stdc++.h>
using namespace std;

constexpr int MAX = 1'000'000;
constexpr int MOD = 1'000'000'009;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    vector<long long> dp(MAX + 1);
    dp[1] = 1; dp[2] = 2; dp[3] = 4;

    for (int i = 4; i <= MAX; i++) {
        dp[i] = ((dp[i - 3] + dp[i - 2]) % MOD + dp[i - 1]) % MOD;
    }

    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        cout << dp[n] << '\n';
    }
}
