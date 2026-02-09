#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int n, k, a; cin >> n >> k >> a;
    int mn = INT_MAX;
    for (int i = 0; i < n; i++) {
        int t, s; cin >> t >> s;

        int ans = k / a;
        if (k % (a * t)) ans += (k / (a * t)) * s;
        else ans += (k / (a * t) - 1) * s;

        mn = min(mn, ans);
    }
    cout << mn;
}
