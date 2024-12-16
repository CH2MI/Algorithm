#include <bits/stdc++.h>
using namespace std;
constexpr double const_pi() { return std::atan(1)*4; }
typedef array<double, 2> point;

int CCW(point& a, point& b, point& c) {
    double ans = a[0] * b[1] + b[0] * c[1] + c[0] * a[1] - (b[0] * a[1] + c[0] * b[1] + a[0] * c[1]);
    if (ans > 0) return 1;
    if (ans < 0) return -1;
    return 0;
}

bool intersect(point& a, point& b, point& c, point& d) {
    int ab = CCW(a, b, c) * CCW(a, b, d);
    int cd = CCW(c, d, a) * CCW(c, d, b);
    if (!ab && !cd) {
        if (a > b) swap(a, b);
        if (c > d) swap(c, d);
        return a <= d && c <= b;
    }
    return ab <= 0 && cd <= 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<array<point, 2>> v(N + 1);
    for (int i = 1; i <= N; i++) {
        double s, e; cin >> s >> e;
        v[i][0][0] = 1000 * cos(s / 1800 * const_pi());
        v[i][0][1] = 1000 * sin(s / 1800 * const_pi());
        v[i][1][0] = 1000 * cos(e / 1800 * const_pi());
        v[i][1][1] = 1000 * sin(e / 1800 * const_pi());
    }
    double sa, sb, ea, eb; cin >> sa >> sb >> ea >> eb;
    v[0][0][0] = sb * cos(sa / 1800 * const_pi());
    v[0][0][1] = sb * sin(sa / 1800 * const_pi());
    v[0][1][0] = eb * cos(ea / 1800 * const_pi());
    v[0][1][1] = eb * sin(ea / 1800 * const_pi());

    bool f = 1;
    for (int i = 1; i <= N; i++) {
        f ^= intersect(v[0][0], v[0][1], v[i][0], v[i][1]);
    }
    if (f) cout << "YES";
    else cout << "NO";
}