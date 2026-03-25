#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int R, C; cin >> R >> C;
    vector<string> v(R);
    for (auto& s : v) cin >> s;

    vector<int> ans(9);

    int rank = 1;
    for (int j = C - 2; j > 0; j--) {
        bool f = 0;
        for (int i = 0; i < R; i++) {
            if (v[i][j] != '.' && !ans[v[i][j] - '1']) ans[v[i][j] - '1'] = rank, f = 1;
        }
        if (f) ++rank;
    }

    for (int i : ans) cout << i << '\n';
}
