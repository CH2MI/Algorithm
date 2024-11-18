#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <cmath>
#define x first
#define y second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> point;

int CCW(point& a, point& b, point& c) {
    ll ans = (a.x * b.y + b.x * c.y + c.x * a.y) - (b.x * a.y + c.x * b.y + a.x * c.y);
    if (ans > 0) return 1;
    if (ans < 0) return -1;
    return 0;
}

int CCW(point& a, point& b, point& c, point &d) {
    ll dx = c.x - b.x, dy = c.y - b.y;
    point t = {d.x - dx, d.y - dy};
    return CCW(a, b, t);
}

ll dist(point& a, point& b) {
    ll dx = b.x - a.x, dy = b.y - a.y;
    return dx * dx + dy * dy;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<point> v(n);
        for (auto& [x, y] : v) cin >> x >> y;

        sort(v.begin(), v.end());
        sort(v.begin() + 1, v.end(), [&](point& a, point& b) -> bool {
            int ccw = CCW(v[0], a, b);
            if (!ccw) return dist(v[0], a) < dist(v[0], b);
            return ccw > 0;
        });

        stack<int> st;
        st.push(0);

        for (int i = 1; i < n; i++) {
            if (st.size() < 2) {
                st.push(i);
                continue;
            }
            int a = st.top(); st.pop();
            int b = st.top();

            if (CCW(v[b], v[a], v[i % n]) > 0) st.push(a), st.push(i);
            else i--;
        }

        vector<point> convex;
        while (!st.empty()) {
            convex.push_back(v[st.top()]);
            st.pop();
        }

        int a = 0, c = 1, l = (int)convex.size();

        point p1 = convex[a], p2 = convex[c];
        ll mx = dist(p1, p2);
        while (a < l) {
            int b = (a + 1) % l, d = (c + 1) % l;
            ll t = dist(convex[a], convex[c]);
            if (t > mx) {
                p1 = convex[a], p2 = convex[c];
                mx = t;
            }
            if (CCW(convex[a], convex[b], convex[c], convex[d]) < 0) c = (c + 1) % l;
            else a++;
        }

        cout << p1.x << ' ' << p1.y << ' ' << p2.x << ' ' << p2.y << '\n';
    }
}