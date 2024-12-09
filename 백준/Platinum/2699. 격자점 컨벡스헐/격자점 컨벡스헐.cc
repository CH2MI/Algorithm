#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef pair<int, int> point;

int CCW(point& a, point& b, point& c) {
    int ans = a.x * b.y + b.x * c.y + c.x * a.y - (b.x * a.y + c.x * b.y + a.x * c.y);
    if (ans > 0) return 1;
    if (ans < 0) return -1;
    return 0;
}

int dist(point& a, point& b) {
    int dx = b.x - a.x, dy = b.y - a.y;
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int P; cin >> P;
    while (P--) {
        int N; cin >> N;
        vector<point> v(N);
        for (auto& [x, y] : v) cin >> x >> y;
        vector<point> c = ConvexHull(v);
        cout << c.size() << '\n';

        int i = max_element(c.begin(), c.end(), [](const point& a, const point& b) {
            return a.y < b.y;
        }) - c.begin();
        for (int j = 0; j < (int)c.size(); j++) {
            auto [x, y] = c[(i + j) % (int)c.size()];
            cout << x << ' ' << y << '\n';
        }
    }

}
