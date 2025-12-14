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
    vector<int> dp(N, 1);

    for (int i = N - 2; i >= 0; i--) {
        if (i + v[i] >= N - 1) continue;
        dp[i] = dp[i + v[i] + 1] + 1;
    }

    for (int i : dp) cout << i << ' ';
}
