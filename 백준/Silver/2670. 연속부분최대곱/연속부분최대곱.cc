#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int N; cin >> N;
    vector<double> v(N);
    for (auto& i : v) cin >> i;
    double mx = 0;
    vector<double> dp(N + 1);
    dp[0] = 1;
    for (int i = 1; i <= N; i++) {
        dp[i] = max(dp[i - 1] * v[i - 1], v[i - 1]);
        mx = max(mx, dp[i]);
    }

    cout << fixed << setprecision(3) << round(mx * 1000) / 1000;
}