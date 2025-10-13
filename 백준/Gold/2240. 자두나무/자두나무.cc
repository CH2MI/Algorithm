#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int T, W;
    cin >> T >> W;

    vector<int> v(T);
    for (int& i : v) cin >> i;
    // dp[i][j][k] = i번째 j번 움직였을 때 위치가 k
    vector dp(T + 1, vector(W + 1, array<int, 2>()));

    dp[1][0][0] = (v[0] == 1);
    dp[1][1][1] = (v[0] == 2);
    for (int i = 2; i <= T; i++) {
        dp[i][0][0] = dp[i - 1][0][0] + (v[i - 1] == 1);
        for (int j = 1; j <= W; j++) {
            dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j - 1][1]) + (v[i - 1] == 1);
            dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][0]) + (v[i - 1] == 2);
        }
    }

    int mx = 0;

    for (int i = 0; i <= W; i++) {
        mx = max({mx, dp.back()[i][0], dp.back()[i][1]});
    }
    cout << mx;
}