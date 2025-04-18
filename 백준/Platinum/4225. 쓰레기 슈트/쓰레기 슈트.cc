#include <bits/stdc++.h>
using namespace std;

typedef array<double, 2> point;

int CCW(point& a, point& b, point& c) {
    double ans = a[0] * b[1] + b[0] * c[1] + c[0] * a[1] - (b[0] * a[1] + c[0] * b[1] + a[0] * c[1]);
    if (ans > 0) return 1;
    if (ans < 0) return -1;
    return 0;
}

double dist(point& a, point& b) {
    double dx = b[0] - a[0], dy = b[1] - a[1];
    return dx * dx + dy * dy;
}

double dist(point& a, point& b, point& c) {
    double ans = a[0] * b[1] + b[0] * c[1] + c[0] * a[1] - (b[0] * a[1] + c[0] * b[1] + a[0] * c[1]);
    return abs(ans) / sqrt(dist(b, c));
}

vector<point> convexhull(vector<point>& v) {
    sort(v.begin(), v.end());
    sort(v.begin() + 1, v.end(), [&](point& a, point& b) {
        int ccw = CCW(v[0], a, b);
        if (!ccw) return dist(v[0], a) < dist(v[0], b);
        return ccw > 0;
    });

    stack<int> st;
    st.push(0);

    for (int i = 1; i < (int)v.size(); i++) {
        if (st.size() < 2) {
            st.push(i);
            continue;
        }
        int a = st.top(); st.pop();
        int b = st.top();

        if (CCW(v[b], v[a], v[i]) > 0) st.push(a), st.push(i);
        else i--;
    }

    vector<point> ch(st.size());
    for (auto& p : ch) p = v[st.top()], st.pop();
    return ch;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int cnt = 1;
    while (1) {
        int N; cin >> N;
        if (!N) break;

        vector<point> v(N);
        for (auto& [x, y] : v) cin >> x >> y;

        vector<point> ch = convexhull(v);

        double mn = DBL_MAX;
        int l = ch.size();
        for (int i = 0; i < l; i++) {
            double mx = 0;
            for (int j = 0; j < l; j++) {
                mx = max(mx, dist(ch[j], ch[i], ch[(i + 1) % l]));
            }
            mn = min(mn, mx);
        }
        cout << fixed;
        cout.precision(2);
        cout << "Case " << cnt++ << ": " << ceil(mn * 100) / 100 << '\n';
    }
}