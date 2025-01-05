#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef array<ll, 2> point;

int CCW(point& a, point& b, point& c) {
    ll ans = a[0] * b[1] + b[0] * c[1] + c[0] * a[1] - (b[0] * a[1] + c[0] * b[1] + a[0] * c[1]);
    if (ans > 0) return 1;
    if (ans < 0) return -1;
    return 0;
}

ll dist(point& a, point& b) {
    ll dx = b[0] - a[0], dy = b[1] - a[1];
    return dx * dx + dy * dy;
}

vector<point> convexhell(vector<point>& v) {
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
        else --i;
    }

    vector<point> ch(st.size());
    for (auto& p : ch) p = v[st.top()], v.erase(v.begin() + st.top()), st.pop();
    return ch;
}

bool isContained(vector<point>& ch, int Px, int Py) {
    point p = {Px, Py};
    int len = (int)ch.size();
    for (int i = 0; i < len; i++) {
        if (CCW(ch[i], ch[(i + 1) % len], p) >= 0) return 0;
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Px, Py; cin >> N >> Px >> Py;
    vector<point> v(N);
    for (auto& [x, y] : v) cin >> x >> y;

    int cnt = 0;
    while ((int)v.size() > 2) {
        vector<point> ch = convexhell(v);
        if (!isContained(ch, Px, Py)) break;
        ++cnt;
    }
    cout << cnt;
}