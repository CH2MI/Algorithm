#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> point;

int CCW(point& a, point& b, point& c) {
    ll ans = a.x * b.y + b.x * c.y + c.x * a.y - (b.x * a.y + c.x * b.y + a.x * c.y);
    if (ans > 0) return 1;
    if (ans < 0) return -1;
    return 0;
}

ll dist(point& a, point& b) {
    ll dx = b.x - a.x, dy = b.y - a.y;
    return (dx * dx + dy * dy);
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

bool separate(vector<point>& black, vector<point>& white) {
    vector<point> bc = ConvexHull(black), wc = ConvexHull(white);

    // 두 컨벡스 헐이 교차하는지 판정
    int bl = (int)bc.size(), wl = (int)wc.size();
    for (int i = 0; i < bl; i++) {
        point p1 = bc[i], p2 = bc[(i + 1) % bl];
        for (int j = 0; j < wl; j++) {
            point p3 = wc[j], p4 = wc[(j + 1) % wl];
            if (intersect(p1, p2, p3, p4)) return false;
        }
    }

    // 두 컨벡스 헐로 새로운 컨벡스 헐을 만든다.
    vector<point> sum(bc);
    sum.insert(sum.end(), wc.begin(), wc.end());
    vector<point> sumc = ConvexHull(sum);

    sort(bc.begin(), bc.end());
    sort(wc.begin(), wc.end());
    sort(sumc.begin(), sumc.end());
    return (sumc != bc && sumc != wc);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        int n, m; cin >> n >> m;
        vector<point> black(n), white(m);
        for (auto& [x, y] : black) cin >> x >> y;
        for (auto& [x, y] : white) cin >> x >> y;

        if (separate(black, white)) cout << "YES\n";
        else cout << "NO\n";
    }
}

