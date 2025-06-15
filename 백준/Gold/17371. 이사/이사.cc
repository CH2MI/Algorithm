#include <bits/stdc++.h>
using namespace std;

typedef array<double, 2> point;

double getDist(point& a, point& b) {
    return (a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1]);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N; cin >> N;
    vector<point> v(N);
    for (auto& [x, y] : v) cin >> x >> y;

    vector<double> dist(N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            dist[i] = max(dist[i], getDist(v[i], v[j]));
        }
    }

    point ans = v[min_element(dist.begin(), dist.end()) - dist.begin()];
    cout << ans[0] << ' ' << ans[1];
}