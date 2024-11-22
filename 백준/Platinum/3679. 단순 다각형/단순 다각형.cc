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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<pair<point, int>> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i].first.x >> v[i].first.y;
            v[i].second = i;
        }
        sort(v.begin(), v.end());
        sort(v.begin() + 1, v.end(), [&](pair<point, int>& a, pair<point, int>& b) {
            int ccw = CCW(v[0].first, a.first, b.first);
            if (!ccw) return dist(v[0].first, a.first) < dist(v[0].first, b.first);
            return ccw > 0;
        });

        int len = n - 1;
        for (; len >= 1; len--) {
            if (CCW(v[0].first, v[len].first, v[len - 1].first)) break;
        }

        for (int i = 0; i < len; i++) {
            cout << v[i].second << ' ';
        }
        for (int i = n - 1; i >= len; i--) {
            cout << v[i].second << ' ';
        }
        cout << '\n';

    }
}