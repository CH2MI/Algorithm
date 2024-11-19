#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef pair<int, int> point;

int CCW(point& a, point& b, point& c) {
    int ans = (a.x * b.y + b.x * c. y + c.x * a.y) - (b.x * a.y + c.x * b.y + a.x * c.y);
    if (ans < 0) return -1;
    if (ans > 0) return 1;
    return 0;
}

int CCW(point& a, point& b, point& c, point& d) {
    int dx = c.x - b.x, dy = c.y - b.y;
    point e = {d.x - dx, d.y - dy};
    return CCW(a, b, e);
}

int dist(point& a, point& b) {
    int dx = b.x - a.x, dy = b.y - a.y;
    return (dx * dx) + (dy * dy);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int C; cin >> C;
    vector<point> v(C);
    for (auto& [x, y] : v) cin >> x >> y;

    sort(v.begin(), v.end());
    sort(v.begin() + 1, v.end(), [&](point& a, point &b) -> bool {
        int ccw = CCW(v[0], a, b);
        if (!ccw) return dist(v[0], a) < dist(v[0], b);
        return ccw > 0;
    });

    stack<int> st;
    st.push(0);

    for (int i = 1; i < C; i++) {
        if (st.size() < 2) {
            st.push(i);
            continue;
        }
        int a = st.top(); st.pop();
        int b = st.top();
        if (CCW(v[b], v[a], v[i]) > 0) st.push(a), st.push(i);
        else i--;
    }

    vector<point> convex;
    convex.reserve(st.size());
    while (!st.empty()) {
        convex.push_back(v[st.top()]);
        st.pop();
    }

    int a = 0, c = 1, l = (int)convex.size(), mx = dist(convex[a], convex[c]);
    while (a < l) {
        int b = (a + 1) % l, d = (c + 1) % l;
        int m = dist(convex[a], convex[c]);
        if (m > mx) mx = m;
        if (CCW(convex[a], convex[b], convex[c], convex[d]) < 0) c = (c + 1) % l;
        else a++;
    }
    cout << fixed;
    cout.precision(8);
    cout << sqrt(mx) << '\n';
}