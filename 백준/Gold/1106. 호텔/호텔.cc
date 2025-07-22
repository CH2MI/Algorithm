#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int C, N; cin >> C >> N;
    vector<array<int, 2>> v(N);

    for (auto& [a, b] : v) cin >> a >> b;


    vector<int> dp(C * 100 + 1);

    for (int i = 0; i <= C * 100; i++) {
        for (int j = 0; j < N; j++) {
            if (i < v[j][0]) continue;
            dp[i] = max(dp[i], dp[i - v[j][0]] + v[j][1]);
        }
    }

    cout << lower_bound(dp.begin(), dp.end(), C) - dp.begin();

}