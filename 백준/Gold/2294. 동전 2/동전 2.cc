#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k; cin >> n >> k;
    vector<int> dp(k + 1, (int)1e9);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        int v; cin >> v;
        for (int j = 1; j <= k; j++) {
            if (v <= j && dp[j - v] + 1 < dp[j]) dp[j] = dp[j - v] + 1;
        }
    }
    if (dp[k] == (int)1e9) cout << -1;
    else cout << dp[k];
}
