#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N, M, q; cin >> N >> M >> q;

    vector v(N, vector<int>(M));
    for (auto& i : v) for (auto& j : i) cin >> j;
    vector<int> r(N);
    for (int i = 0; i < N; i++) r[i] = i;

    for (int i = 0; i < q; i++) {
        int a; cin >> a;
        if (a) {
            int b, c; cin >> b >> c;
            swap(r[b], r[c]);
        }
        else {
            int b, c, d; cin >> b >> c >> d;
            v[r[b]][c] = d;
        }
    }
    vector ans(v);
    for (int i = 0; i < N; i++) {
        ans[i] = v[r[i]];
    }

    for (auto& i : ans) {
        for (auto j : i) cout << j << ' ';
        cout << '\n';
    }
}