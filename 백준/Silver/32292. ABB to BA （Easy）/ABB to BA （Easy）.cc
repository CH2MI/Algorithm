#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N; cin >> N;

    string s; cin >> s;

    while (1) {
        int f = 0;
        for (int i = 0; i < N - 2; i++) {
            if (s.substr(i, 3) == "ABB") {
                f = 1;
                string tmp = s.substr(0, i) + "BA" + s.substr(i + 3);
                s = tmp;
                N = (int)s.size();
                break;
            }
        }
        if (!f) break;
    }
    cout << s << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    #ifdef LOCAL_DEBUG
        freopen("input.txt", "r", stdin);
    #endif

    int T; cin >> T;
    while (T--) solve();
}
