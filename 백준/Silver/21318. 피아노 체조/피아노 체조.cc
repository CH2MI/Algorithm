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

    vector<int> dp(N + 1);
    for (int i = 1; i < N; i++) {
        dp[i] = dp[i - 1] + (v[i - 1] > v[i]);
    }
    dp[N] = dp[N - 1];


    int Q; cin >> Q;
    for (int i = 0; i < Q; i++) {
        int s, e; cin >> s >> e;

        int ans = dp[e] - dp[s - 1];

        if (e != N && v[e - 1] > v[e])
            --ans;

        cout << ans << '\n';
    }
}
