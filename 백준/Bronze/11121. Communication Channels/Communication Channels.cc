#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T; cin >> T;
    for (int i = 0; i < T; i++) {
        string a, b; cin >> a >> b;
        if (a == b) cout << "OK\n";
        else cout << "ERROR\n";
    }
}