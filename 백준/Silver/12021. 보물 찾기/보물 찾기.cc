#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    double a, b, a1, b1; cin >> a >> b;

    while (1) {
        a1 = (a + b) / 2;
        b1 = 2 * a * b / (a + b);

        if (abs(a - a1) < 1e-6 && abs(b - b1) < 1e-6) break;
        a = a1; b = b1;
    }

    cout << fixed;
    cout.precision(6);
    cout << a1 << ' ' << b1;
}