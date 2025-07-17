#include <bits/stdc++.h>
using namespace std;

long long cal(vector<array<long long, 2>>& v) {
    if (v.empty()) return 0;
    auto [mnx, mxx] = minmax_element(v.begin(), v.end(), [](auto& a, auto& b) { return a[0] < b[0]; });
    auto [mny, mxy] = minmax_element(v.begin(), v.end(), [](auto& a, auto& b) { return a[1] < b[1]; });
    return ((*mxx)[0] - (*mnx)[0] + 1) * ((*mxy)[1] - (*mny)[1] + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int R, C; cin >> R >> C;
    int N; cin >> N;

    vector<vector<array<long long, 2>>> v(N);

    for (int i = 0; i < N; i++) {
        long long a, b, c; cin >> a >> b >> c;
        v[a - 1].push_back({b, c});
    }

    long long mx = cal(v[0]), k = 0;
    for (int i = 1; i < N; i++) {
        long long t = cal(v[i]);
        if (mx < t) {
            mx = t;
            k = i;
        }
    }

    cout << k + 1 << ' ' << mx;
}