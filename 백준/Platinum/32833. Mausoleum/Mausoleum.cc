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

double dist(point& a, point& b) {
    ll dx = b.x - a.x, dy = b.y - a.y;
    return sqrt(dx * dx + dy * dy);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<point> v;
    v.reserve(n << 1);

    for (int i = 0; i < n >> 1; i++) {
        ll x, y;
        cin >> x >> y;
        if (v.empty()) v.emplace_back(0, 0);
        else v.emplace_back(x, v.back().y);
        v.emplace_back(x, y);
    }
    point s, t;
    cin >> s.x >> s.y >> t.x >> t.y;

    int m = upper_bound(v.begin(), v.end(), t) - v.begin() - 1;
    int l = (int)v.size();
    vector<double> in(v.size()), out(v.size(), LLONG_MAX);
    stack<int> st({l});
    for (int i = m; i >= 0; i--) {
        if (st.size() < 2) {
            in[i] = dist(v[i], t);
            st.push(i);
            continue;
        }
        int a = st.top(); st.pop();
        int b = st.top();
        if (CCW(b == l ? t : v[b], v[a], v[i]) >= 0) i++;
        else in[i] = dist(v[i], v[a]) + in[a], st.push(a), st.push(i);
    }
    st = stack<int>({l});
    for (int i = m + 1; i < (int)v.size(); i++) {
        if (st.size() < 2) {
            in[i] = dist(v[i], t);
            st.push(i);
            continue;
        }
        int a = st.top(); st.pop();
        int b = st.top();
        if (CCW(b == l ? t : v[b], v[a], v[i]) <= 0) i--;
        else in[i] = dist(v[i], v[a]) + in[a], st.push(a), st.push(i);
    }

    m = upper_bound(v.begin(), v.end(), s) - v.begin() - 1;

    if (s.x < 0) m = 0;
    else if (s.x > v.back().x) m = l - 1;
    else if (s.y < 0) m = 0;

    st = stack<int>({l});

    for (int i = 0; i < l; i++) {
        int j = (m - i + l) % l;
        if (st.size() < 2) {
            out[j] = min(out[j], dist(v[j], s));
            st.push(j);
            continue;
        }
        int a = st.top(); st.pop();
        int b = st.top();
        if (CCW(b == l ? s : v[b], v[a], v[j]) <= 0) i--;
        else out[j] = min(out[j], dist(v[j], v[a]) + out[a]), st.push(a), st.push(j);
    }
    st = stack<int>({l});
    for (int i = 0; i < l; i++) {
        int j = (m + i) % l;
        if (st.size() < 2) {
            out[j] = min(out[j], dist(v[j], s));
            st.push(j);
            continue;
        }
        int a = st.top(); st.pop();
        int b = st.top();
        if (CCW(b == l ? s : v[b], v[a], v[j]) >= 0) i--;
        else out[j] = min(out[j], dist(v[j], v[a]) + out[a]), st.push(a), st.push(j);
    }

    double mn = DBL_MAX;
    for (int i = 0; i < l; i++) {
        mn = min(mn, in[i] + out[i]);
    }
    cout << fixed;
    cout.precision(8);
    cout << mn;

}