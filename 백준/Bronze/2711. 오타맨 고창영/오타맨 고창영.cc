#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        int n; string s;
        cin >> n >> s;
        for (int i = 0; i < (int)s.size(); i++) {
            if (i + 1 == n) continue;
            cout << s[i];
        }
        cout << '\n';
    }
}