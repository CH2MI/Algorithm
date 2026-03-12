#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int N; cin >> N;

    vector<array<int, 2>> dp(N + 1);
    dp[1][0] = 1;
    for (int i = 2; i <= N; i++) {
        dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % 10;
        dp[i][1] = dp[i - 1][0];
    }

    cout << (dp[N][0] + dp[N][1]) % 10;
}
