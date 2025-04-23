#include <bits/stdc++.h>
using namespace std;

typedef array<int, 2> point;

int cal(vector<point>& h) {
    vector<point> v(h.size() * 2);

    for (int i = 0; i < h.size(); i++) {
        if (h[i][0] > h[i][1]) swap(h[i][0], h[i][1]);
        v[i * 2] = {h[i][0], i + 1};
        v[i * 2 + 1] = {h[i][1], -(i + 1)};
    }
    sort(v.begin(), v.end());

    int cnt = 0, mx = 0;

    for (auto [p, n] : v) {
        if (n < 0) {
            --cnt;
        }
        else {
            mx = max(mx, ++cnt);
        }
    }
    return mx;
}


int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N; cin >> N;
    vector<point> v(N);
    for (auto& [x, y] : v) cin >> x >> y;

    vector<point> h, w;
    for (int i = 1; i <= N; i++) {
        if (v[i - 1][0] == v[i % N][0]) {
            h.push_back({v[i - 1][1], v[i % N][1]});
        }
        else {
            w.push_back({v[i - 1][0], v[i % N][0]});
        }
    }

    cout << max(cal(h), cal(w));
}
