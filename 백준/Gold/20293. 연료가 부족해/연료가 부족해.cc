#include <bits/stdc++.h>
using namespace std;

int R, C;
vector<vector<int>> fuel;

int solve(int mid) {
    vector dp(R + 1, vector<int>(C + 1));
    fuel[0][0] = mid;
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            if (i == 1 && j == 1) {
                dp[i][j] = fuel[i - 1][j - 1];
                continue;
            }
            dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]) - 1;
            if (dp[i][j] >= 0) dp[i][j] += fuel[i - 1][j - 1];
        }
    }
    fuel[0][0] = 0;

    return dp[R][C] >= 0;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> R >> C;
    fuel.assign(R, vector<int>(C));

    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        int r, c, f;
        cin >> r >> c >> f;
        fuel[r - 1][c - 1] = f;
    }

    int lo = 0, hi = R + C;
    while (lo + 1 < hi) {
        int mid = (lo + hi) / 2;
        if (solve(mid)) hi = mid;
        else lo = mid;
    }
    cout << hi;
}