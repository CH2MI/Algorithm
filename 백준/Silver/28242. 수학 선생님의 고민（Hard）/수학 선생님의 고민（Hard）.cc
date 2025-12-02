#include <bits/stdc++.h>
using namespace std;

int solve(int a, int b, int c, int d, int n) {
    if (b * c - a * d == n + 1) {
        cout << a << ' ' << b << ' ' << c << ' ' << -d << '\n';
        return 1;
    }
    if (a * d - b * c == n + 1) {
        cout << a << ' ' << -b << ' ' << c << ' ' << d << '\n';
        return 1;
    }
    return 0;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int n; cin >> n;
    
    vector<int> v; v.reserve(n);

    for (int i = 1; i <= n; i++) {
        if (n % i == 0) v.push_back(i);
    }

    int f = 1;
    for (int i = 1; i <= n + 2 && f; i++) {
        if ((n + 2) % i == 0) {
            for (int j : v) {
                if (solve(j, i, n / j, (n + 2) / i, n)) {
                    f = 0;
                    break;
                }
            }
        }
    }

    if (f) cout << -1;

}
