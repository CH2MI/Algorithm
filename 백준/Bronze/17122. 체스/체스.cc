#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int T; cin >> T;
    while (T--) {
        string s; cin >> s;
        int n; cin >> n;

        if (((s[0] - 'A') % 2 ^ (s[1] - '1') % 2) == ((n - 1) / 8 % 2 ^ (n - 1) % 8 % 2)) cout << "YES\n";
        else cout << "NO\n";
    }
}
