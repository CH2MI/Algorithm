#include <bits/stdc++.h>
using namespace std;

typedef array<int, 2> point;

int CCW(point& a, point& b, point& c) {
    int ans = a[0] * b[1] + b[0] * c[1] + c[0] * a[1] - (b[0] * a[1] + c[0] * b[1] + a[0] * c[1]);
    if (ans > 0) return 1;
    if (ans < 0) return -1;
    return 0;
}

int CCW(point& a, point& b, point& c, point &d) {
    int dx = c[0] - b[0], dy = c[1] - b[1];
    point e = {d[0] - dx, d[1] - dy};
    return CCW(a, b, e);
}

int dist(point& a, point& b) {
    int dx = b[0] - a[0], dy = b[1] - a[1];
    return dx * dx + dy * dy;
}

vector<point> ConvexHull(vector<point>& v) {
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

    vector<point> c(st.size());
    for (auto& p : c) p = v[st.top()], st.pop();
    return c;
}

array<point, 2> calipers(vector<point>& convex) {
    int a = 0, c = 1, l = (int)convex.size();

    point p1 = convex[a], p2 = convex[c];
    int mx = dist(p1, p2);
    while (a < l) {
        int b = (a + 1) % l, d = (c + 1) % l;
        int t = dist(convex[a], convex[c]);
        if (t > mx) {
            p1 = convex[a], p2 = convex[c];
            mx = t;
        }
        if (CCW(convex[a], convex[b], convex[c], convex[d]) < 0) c = (c + 1) % l;
        else a++;
    }
    return {p1, p2};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<point> v(N);
    for (auto& [x, y] : v) cin >> x >> y;
    vector<point> ch = ConvexHull(v);
    auto ans = calipers(ch);
    cout << dist(ans[0], ans[1]);
}