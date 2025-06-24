#include <bits/stdc++.h>
using namespace std;

int r;
vector<int> v;

int solve(int mid) {
    long long cnt = 0;
    for (int i : v) cnt += mid / i + 1ll;
    return r <= cnt;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, s, m;
    cin >> n >> s >> m;
    r = n - s;
    v.assign(m, 0);
    for (int& i : v) cin >> i;

    if (r <= m) {
        cout << r;
        return 0;
    }

    int lo = 1, hi = (int)1e8;
    while (lo + 1 < hi) {
        int mid = (lo + hi) / 2;
        if (solve(mid)) hi = mid;
        else lo = mid;
    }

    int ans = 1;
    long long cnt = 0;
    for (int i = 0; i < m; i++) {
        if (hi % v[i] == 0) ans = i + 1;
        cnt += hi / v[i] + 1ll;
    }

    int i = m - 1;
    while (r <= cnt && i > -1) {
        if (hi % v[i] == 0) {
            if (cnt-- == r) {
                ans = i + 1;
                break;
            }
        }
        i--;
    }

    cout << ans;
}