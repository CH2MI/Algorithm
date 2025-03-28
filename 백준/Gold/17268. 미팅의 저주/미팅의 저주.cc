#include <bits/stdc++.h>
using namespace std;

constexpr long long mod = 987654321;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N; cin >> N;

    vector<long long> dp(N + 1);
    dp[0] = dp[2] = 1;

    for (int i = 4; i <= N; i += 2) {
        for (int j = 0; j < i; j += 2) {
            dp[i] = ((dp[j] * dp[i - 2 - j]) % mod + dp[i]) % mod;
        }
    }
    cout << dp[N];
}