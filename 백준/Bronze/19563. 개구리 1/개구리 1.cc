#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int a, b, c; cin >> a >> b >> c;

    if (!c) {
        if (!a && !b) cout << "YES";
        else cout << "NO";
    }
    else if (abs(a) + abs(b) > c) cout << "NO";
    else if ((abs(a) + abs(b)) % 2 == c % 2) cout << "YES";
    else cout << "NO";
}