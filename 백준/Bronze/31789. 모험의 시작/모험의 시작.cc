#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N; cin >> N;
    int X, S; cin >> X >> S;
    int mx = 0;

    for (int i = 0; i < N; i++) {
        int c, p; cin >> c >> p;
        if (c <= X) mx = max(mx, p);
    }

    if (S < mx) cout << "YES";
    else cout << "NO";
}