#include <bits/stdc++.h>
using namespace std;

void solve (int tc) {
    string a, b, c;
    cin >> a >> b >> c;

    vector<vector<int>> dp(a.size() + 1, vector<int>(b.size() + 1));
    dp[0][0] = 1;

    for (int i = 0; i <= (int)a.size(); i++) {
        for (int j = 0; j <= (int)b.size(); j++) {
            if (!i && !j) continue;

            if (i) dp[i][j] |= dp[i - 1][j] & (a[i - 1] == c[i + j - 1]);
            if (j) dp[i][j] |= dp[i][j - 1] & (b[j - 1] == c[i + j - 1]);
        }
    }

    cout << "Data set " << tc << ": ";
    if (dp.back().back()) cout << "yes\n";
    else cout << "no\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int T; cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }

}