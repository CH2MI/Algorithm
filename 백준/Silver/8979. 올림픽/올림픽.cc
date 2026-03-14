#include <bits/stdc++.h>
using namespace std;

int cmp(array<int, 4>& a, array<int, 4> b) {
    if (a[1] == b[1] && a[2] == b[2] && a[3] == b[3]) return 0;
    if (a[1] == b[1] && a[2] == b[2]) return a[3] > b[3];
    if (a[1] == b[1]) return a[2] > b[2];
    return a[1] > b[1];
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int N, M; cin >> N >> M;
    vector<array<int, 4>> v(N);

    for (auto& i : v) for (int& j : i) cin >> j;

    int idx = 0;
    for (; idx < N; idx++) {
        if (v[idx][0] == M) break;
    }

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        if (cmp(v[i], v[idx])) cnt++;
    }
    cout << cnt + 1;
}
