#include <bits/stdc++.h>
using namespace std;

int n;
vector<array<int, 2>> v;

int go(int cur, int r, int g) {
    if (cur == n && !r) return g;
    if (cur == n) return 0;
    if (r < 0) return 0;

    int mx = 0;
    for (int i = 1; i <= r; i++) {
        if (v[cur][0] * i + v[cur][1] < g) continue;
        if (v[cur][0] * i + v[cur][1] > g) break;
        mx = max(mx, go(cur + 1, r - i, g));
    }

    return mx;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> n;
    v.assign(n, array<int, 2>());
    for (auto& [a, b] : v) cin >> a >> b;
    int M; cin >> M;
    int mx = 0;
    for (int i = 1; i <= M; i++)
        mx = max(mx, go(1, M - i, v[0][0] * i + v[0][1]));

    cout << mx;
}