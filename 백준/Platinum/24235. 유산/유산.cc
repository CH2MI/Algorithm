#include <bits/stdc++.h>
using namespace std;

typedef array<double, 2> point;

double area(point& a, point& b, point& c) {
    return (a[0] * b[1] + b[0] * c[1] + c[0] * a[1] - (b[0] * a[1] + c[0] * b[1] + a[0] * c[1])) / 2;
}

int CCW(point& a, point& b, point& c) {
    double ans = area(a, b, c);
    if (ans > 0) return 1;
    if (ans < 0) return -1;
    return 0;
}

int dist(point& a, point& b) {
    int dx = b[0] - a[0], dy = b[1] - a[1];
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

void sep(vector<point>& ch, vector<point>& up, vector<point>& down) {
    int l = (int)ch.size();
    up.push_back(ch[l - 1]); down.push_back(ch[l - 1]);

    int i = 0;
    while (ch[i][0] <= ch[i + 1][0]) {
        up.push_back(ch[i++]);
    }
    up.push_back(ch[i]);
    int j = l - 2;
    while (i <= j) {
        down.push_back(ch[j--]);
    }
}

point intersection(point& a, point& b, double c) {
    double t = (c - a[0]) / (b[0] - a[0]);
    return {c, a[1] + t * (b[1] - a[1])};
}

double area(vector<point>& a) {
    double sum = 0;
    for (int i = 2; i < (int)a.size(); i++) {
        sum += abs(area(a[0], a[i - 1], a[i]));
    }
    return sum;
}

int solve(vector<point>& up, vector<point>& down, double mid) {
    point m = {mid, 0};
    int ui = lower_bound(up.begin(), up.end(), m) - up.begin();
    int di = lower_bound(down.begin(), down.end(), m) - down.begin();

    point u = intersection(up[ui - 1], up[ui], mid);
    point d = intersection(down[di - 1], down[di], mid);

    vector<point> p1;
    p1.reserve(up.size() + down.size());
    for (int i = 0; i < di; i++) p1.push_back(down[i]);
    p1.push_back(d);
    p1.push_back(u);
    for (int i = ui - 1; i > 0; i--) p1.push_back(up[i]);

    vector<point> p2;
    p2.reserve(up.size() + down.size());
    p2.push_back(d);
    for (int i = di; i < down.size(); i++) p2.push_back(down[i]);
    for (int i = up.size() - 2; i >= ui; i--) p2.push_back(up[i]);
    p2.push_back(u);

    double left = area(p1), right = area(p2);

    return left < right;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<point> v(N);
    for (auto& [x, y] : v) cin >> x >> y;

    vector<point> ch(convexhull(v));

    vector<point> up, down;
    sep(ch, up, down);

    double lo = up[0][0], hi = up[up.size() - 1][0];
    while (lo+1e-5<hi) {
        double mid = (lo + hi) / 2;
        if (solve(up, down, mid)) lo = mid;
        else hi = mid;
    }
    cout << fixed;
    cout.precision(4);
    cout << lo;
}