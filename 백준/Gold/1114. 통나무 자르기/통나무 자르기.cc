#include <bits/stdc++.h>
using namespace std;

int L, K, C;
vector<int> v;

int solve(int mid) {
    int pre = L;
    int c = C;

    for (int i = K; i > 0; i--) {
        if (pre - v[i] > mid) return 0;
        if (pre - v[i - 1] > mid) {
            if (!c) return 0;
            pre = v[i];
            --c;
        }
    }
    return pre - v.front() <= mid;
}

int ans(int mid) {
    int pre = L;
    int c = C;

    vector<int> cut(K + 1);
    for (int i = K; i > 0; i--) {
        if (pre - v[i - 1] > mid) {
            pre = v[i];
            --c;
            cut[i] = 1;
        }
    }

    if (c) return v[1];

    return pre;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> L >> K >> C;
    v.assign(K, 0);
    for (int& i : v) cin >> i;

    v.push_back(0);
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());


    int lo = 0, hi = L + 1;
    while (lo + 1 < hi) {
        int mid = (lo + hi) / 2;
        if (solve(mid)) hi = mid;
        else lo = mid;
    }
    cout << hi << ' ' << ans(hi);
}