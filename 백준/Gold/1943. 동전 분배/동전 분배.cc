#include <bits/stdc++.h>
using namespace std;

int N, T;
vector<array<int, 2>> v;
vector<vector<int>> dp;

int go(int t, int a) {
    if (t == T) return 1;
    if (t > T) return 0;
    if (a == N) return 0;

    if (dp[t][a] != -1) return dp[t][a];

    int ans = 0;
    for (int i = 0; i <= v[a][1]; i++) {
        ans |= go(t + v[a][0] * i, a + 1);
    }

    return dp[t][a] = ans;
}

void solve() {
    cin >> N;
    v.assign(N, array<int, 2>());

    int sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> v[i][0] >> v[i][1];
        sum += v[i][0] * v[i][1];
    }

    if (sum % 2) {
        cout << 0 << '\n';
        return;
    }
    T = sum / 2;
    dp.assign(T + 1, vector<int>(N, -1));

    cout << go(0, 0) << '\n';

}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    for (int a = 0; a < 3; a++) {
        solve();
    }
}