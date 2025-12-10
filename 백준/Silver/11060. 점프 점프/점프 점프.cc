#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int N; cin >> N;
    vector<int> v(N);
    for (int& i : v) cin >> i;

    vector<int> dp(N, INT_MAX);
    dp[0] = 0;
    for (int i = 0; i < N; i++) {
        if (dp[i] == INT_MAX) continue;
        for (int j = 1; j <= v[i] && i + j < N; j++) {
            dp[i + j] = min(dp[i + j], dp[i] + 1);
        }
    }

    if (dp.back() == INT_MAX) cout << -1;
    else cout << dp.back();

}
