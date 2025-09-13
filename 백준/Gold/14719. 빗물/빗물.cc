#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int H, W; cin >> H >> W;
    vector<int> v(W);
    for (int& i : v) cin >> i;

    int sum = 0;

    for (int i = 0; i < W; i++) {
        int l = 0, r = 0;

        for (int j = i - 1; j >= 0; j--) l = max(l, v[j]);
        for (int j = i + 1; j < W; j++) r = max(r, v[j]);

        int ans = min(l, r);
        if (ans <= v[i]) continue;
        sum += ans - v[i];

    }
    cout << sum;
}
