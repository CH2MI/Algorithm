#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s; cin >> s;
    cout << stoi(s, 0, 2) << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T; cin >> T;
    cin.ignore();
    while (T--) {
        solve();
    }
}