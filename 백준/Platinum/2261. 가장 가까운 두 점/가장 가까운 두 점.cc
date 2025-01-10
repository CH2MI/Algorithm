#include <bits/stdc++.h>
using namespace std;

typedef array<int, 2> point;
vector<point> v;

int dist(point& a, point& b) {
    int dx = b[0] - a[0], dy = b[1] - a[1];
    return dx * dx + dy * dy;
}

int ClosestPair(int s, int e) {
    if (e - s < 2) return dist(v[s], v[e]);
    if (e - s == 2) return min({dist(v[s], v[s + 1]), dist(v[s], v[e]), dist(v[s + 1], v[e])});

    int mid = (s + e) / 2;
    int ret = min(ClosestPair(s, mid), ClosestPair(mid + 1, e));

    int l = (v[mid][0] + v[mid + 1][0]) / 2;
    vector<point> t;
    t.reserve(e - s + 1);
    for (int i = s; i <= e; i++) {
        int dx = l - v[i][0];
        if (dx * dx < ret) t.push_back({v[i][1], v[i][0]});
    }
    sort(t.begin(), t.end());

    for (int i = 0; i < (int)t.size(); i++) {
        for (int j = i + 1; j < (int)t.size(); j++) {
            int dy = t[i][0] - t[j][0];
            if (dy * dy >= ret) break;
            ret = min(ret, dist(t[i], t[j]));
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    v.assign(N, point());
    for (auto& [x, y] : v) cin >> x >> y;
    sort(v.begin(), v.end());
    cout << ClosestPair(0, N - 1);
}