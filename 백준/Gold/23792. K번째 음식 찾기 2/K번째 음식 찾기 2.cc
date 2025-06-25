#include <bits/stdc++.h>
using namespace std;

int N;
vector<vector<int>> v;

int solve(array<int, 3> r, int q, int mid, int i) {
    auto& v1 = v[(i + 1) % 3];
    auto& v2 = v[(i + 2) % 3];
    int cnt = mid;
    cnt += upper_bound(v1.begin(), v1.begin() + r[(i + 1) % 3], v[i][mid]) - v1.begin();
    cnt += upper_bound(v2.begin(), v2.begin() + r[(i + 2) % 3], v[i][mid]) - v2.begin();
    return cnt + 1 <= q;
}

int test(array<int, 3> r, int q, int mid, int i) {
    auto& v1 = v[(i + 1) % 3];
    auto& v2 = v[(i + 2) % 3];
    int cnt = mid;
    cnt += upper_bound(v1.begin(), v1.begin() + r[(i + 1) % 3], v[i][mid]) - v1.begin();
    cnt += upper_bound(v2.begin(), v2.begin() + r[(i + 2) % 3], v[i][mid]) - v2.begin();
    return cnt + 1 == q;
}

array<int, 2> cal(array<int, 3> r, int q) {
    int x = 0, y = 0;

    for (int i = 0; i < 3; i++) {
        int lo = 0, hi = r[i];
            while (lo + 1 < hi) {
            int mid = lo + (hi - lo) / 2;
            if (solve(r, q, mid, i)) lo = mid;
            else hi = mid;
        }
        if (test(r, q, lo, i)) return {i + 1, lo + 1};
    }
    return {0, 0};
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> N;
    v.assign(3, vector<int>(N));
    for (auto& i : v) for (int& j : i) cin >> j;

    int Q; cin >> Q;
    for (int i = 0; i < Q; i++) {
        int a, b, c, q; cin >> a >> b >> c >> q;
        auto [x, y] = cal({a, b, c}, q);
        cout << x << ' ' << y << '\n';
    }
}