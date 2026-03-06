#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    vector<array<int, 2>> v;

    for (int i = 1; i <= 200; i++) for (int j = i + 1; j <= 200; j++) v.push_back({i, j});

    sort(v.begin(), v.end(), [](auto& a, auto& b) {
        int da = a[0] * a[0] + a[1] * a[1];
        int db = b[0] * b[0] + b[1] * b[1];
        if (da == db) return a[0] < b[0];
        return da < db;
    });

    while (1) {
        int h, w; cin >> h >> w;
        if (!h && !w) break;

        auto itr = find(v.begin(), v.end(), array<int, 2>{h, w});
        ++itr;

        cout << (*itr)[0] << ' ' << (*itr)[1] << '\n';
    }
}
