#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s; getline(cin, s);
    array<int, 26> v{};
    for (char c : s) {
        if (c < 'A' || (c > 'Z' && c < 'a')) continue;
        if (c < 'a') v[c - 'A'] = 1;
        else v[c - 'a'] = 1;
    }
    if (count(v.begin(), v.end(), 0) == 0) cout << "pangram\n";
    else {
        cout << "missing ";
        for (int i = 0; i < 26; i++) {
            if (!v[i]) cout << (char)(i + 'a');
        }
        cout << '\n';
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T; cin >> T;
    cin.ignore();
    while (T--) {
        solve();
    }
}