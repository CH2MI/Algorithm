#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
#include <cmath>
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, L; cin >> N >> L;
    vector<point> v(N);
    for (auto& [x, y] : v) cin >> x >> y;

    sort(v.begin(), v.end());

    sort(v.begin() + 1, v.end(), [&](point& a, point& b) -> bool {
        int ccw = CCW(v[0], a, b);
        if (!ccw) return dist(v[0], a) < dist(v[0], b);
        return ccw > 0;
    });

    stack<int> st;
    st.push(0);

    for (int i = 1; i < N; i++) {
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

    double sum = 2 * L * M_PI;
    for (int i = 0; i < c.size(); i++) {
        sum += sqrt(dist(c[i], c[(i + 1) % (int)c.size()]));
    }

    cout << round(sum);
}
