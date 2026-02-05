#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    string s, t;

    while (cin >> s >> t) {
        int i = 0, j = 0;

        while (i < s.size() && j < t.size()) {
            if (s[i] == t[j]) ++i;
            ++j;
        }

        if (i == s.size()) cout << "Yes\n";
        else cout << "No\n";
    }
}
