#include <bits/stdc++.h>
using namespace std;

int a, b;

inline char E(int X) {
    return (a * X + b) % 26 + 'A';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        cin >> a >> b;
        string s; cin >> s;
        for (auto& c : s) {
            cout << E(c - 'A');
        }
        cout << '\n';
    }
}