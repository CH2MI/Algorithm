#include <bits/stdc++.h>
using namespace std;

void solve() {
    int d, n, s, p; cin >> d >> n >> s >> p;
    int S = n * s;
    int P = d + n * p;
    if (S < P) cout << "do not parallelize\n";
    else if (S > P) cout << "parallelize\n";
    else cout << "does not matter\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T; cin >> T;
    cin.ignore();
    while (T--) {
        solve();
    }
}