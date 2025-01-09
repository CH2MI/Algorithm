#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef array<ll, 2> point;

int N;

int CCW(point& a, point& b, point& c) {
    ll ans = a[0] * b[1] + b[0] * c[1] + c[0] * a[1] - (b[0] * a[1] + c[0] * b[1] + a[0] * c[1]);
    if (ans > 0) return 1;
    if (ans < 0) return -1;
    return 0;
}

int cal(vector<point>& v) {
    int mx = -1;
    int l = 0, r = 0;

    while (r < N) {
        if (r - l < 2) {
            ++r;
            continue;
        }

        if (CCW(v[r - 2], v[r - 1], v[r]) > 0) {
            if (CCW(v[r - 1], v[r], v[l]) > 0 && CCW(v[r], v[l], v[l + 1]) > 0) mx = max(mx, r - l + 1), r++;
            else l++;
        }
        else l++;
    }
    return mx;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    vector<point> v(N);
    for (auto& [x, y] : v) cin >> x >> y;

    cout << cal(v);
}