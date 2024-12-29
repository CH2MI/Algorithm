#include <bits/stdc++.h>
#define INF (ll)1e9
using namespace std;

typedef long long ll;
typedef array<ll, 2> point;

int N, T;
vector<array<int, 4>> v;

int CCW(point& a, point& b, point& c) {
    ll ans = a[0] * b[1] + b[0] * c[1] + c[0] * a[1] - (b[0] * a[1] + c[0] * b[1] + a[0] * c[1]);
    if (ans > 0) return 1;
    if (ans < 0) return -1;
    return 0;
}

int CCW(point& a, point& b, point& c, point &d) {
    ll dx = c[0] - b[0], dy = c[1] - b[1];
    point e = {d[0] - dx, d[1] - dy};
    return CCW(a, b, e);
}

ll dist(point& a, point& b) {
    ll dx = b[0] - a[0], dy = b[1] - a[1];
    return dx * dx + dy * dy;
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

ll calipers(vector<point>& ch) {
    int a = 0, c = 1, l = (int)ch.size();

    point p1 = ch[a], p2 = ch[c];
    ll mx = dist(p1, p2);
    while (a < l) {
        int b = (a + 1) % l, d = (c + 1) % l;
        ll t = dist(ch[a], ch[c]);
        if (t > mx) {
            p1 = ch[a], p2 = ch[c];
            mx = t;
        }
        if (CCW(ch[a], ch[b], ch[c], ch[d]) < 0) c = (c + 1) % l;
        else a++;
    }
    return dist(p1, p2);
}

ll solve(int t) {
    vector<point> p(N);
    for (int i = 0; i < N; i++) {
        p[i][0] = v[i][0] + v[i][2] * t;
        p[i][1] = v[i][1] + v[i][3] * t;
    }

    vector<point> ch = convexhull(p);
    return calipers(ch);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> T;
    v.assign(N, array<int, 4>());

    for (int i = 0; i < N; i++) for (int j = 0; j < 4; j++) cin >> v[i][j];

    int lo = 0, hi = T;
    while (lo + 2 < hi) {
        int l = lo + (hi - lo) / 3;
        int r = hi - (hi - lo) / 3;
        if (solve(l) <= solve(r)) hi = r;
        else lo = l;
    }
    vector<point> ans = {{solve(lo), lo}, {solve(lo + 1), lo + 1}, {solve(hi), hi}};
    auto itr = min_element(ans.begin(), ans.end());
    cout << (*itr)[1] << '\n' << (*itr)[0];
}