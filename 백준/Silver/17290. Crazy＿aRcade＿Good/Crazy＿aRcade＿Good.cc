#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int sx, sy; cin >> sx >> sy;
    vector<string> v(10);
    for (auto& s : v) cin >> s;

    vector<int> r(10), c(10);

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (v[i][j] == 'o') {
                r[i] = c[j] = 1;
            }
        }
    }

    int mn = INT_MAX;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (!r[i] && !c[j]) {
                mn = min(mn, abs(sx - i - 1) + abs(sy - j - 1));
            }
        }
    }

    cout << mn;

}

