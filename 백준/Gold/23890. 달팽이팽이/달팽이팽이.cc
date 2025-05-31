#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    long long R; cin >> R;
    long long b = R - 1;
    long long a = sqrt(2 * R + 1);

    if (a * a + b * b >= R * R) {
        cout << a - 1 << ' ' << b;
    }
    else cout << a << ' ' << b;
}