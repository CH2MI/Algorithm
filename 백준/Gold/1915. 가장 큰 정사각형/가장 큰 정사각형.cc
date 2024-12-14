#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    vector<string> v(n);
    vector<vector<int>> dp(n, vector<int>(m));
    for (auto& s : v) cin >> s;

    int mx = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (v[i][j] == '0') dp[i][j] = 0;
            else if (!i || !j) dp[i][j] = 1;
            else dp[i][j] = min({dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]}) + 1;
            mx = max(mx, dp[i][j]);
        }
    }
    cout << mx * mx;
}
