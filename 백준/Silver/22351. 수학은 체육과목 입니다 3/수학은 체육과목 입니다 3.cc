#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s; cin >> s;
    for (int i = 1; i <= 999; i++) {
        string t;
        for (int j = i; j <= 999; j++) {
            t += to_string(j);
            if (t.size() > s.size()) break;
            if (s == t) {
                cout << i << ' ' << j;
                return;
            }
        }
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    solve();
}
