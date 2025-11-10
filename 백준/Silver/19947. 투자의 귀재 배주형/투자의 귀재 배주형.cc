#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int H, Y; cin >> H >> Y;

    vector<array<int, 3>> dp(Y + 1);

    dp[0] = {H, H, H};

    for (int i = 1; i <= Y; i++) {
        dp[i][0] = max({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]}) * 1.05;
        if (i > 2) dp[i][1] = max({dp[i - 3][0], dp[i - 3][1], dp[i - 3][2]}) * 1.2;
        if (i > 4) dp[i][2] = max({dp[i - 5][0], dp[i - 5][1], dp[i - 5][2]}) * 1.35;
    }

    cout << max({dp[Y][0], dp[Y][1], dp[Y][2]});
}
