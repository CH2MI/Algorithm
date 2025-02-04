#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        int a, b; cin >> a >> b;
        int mn = INT_MAX;
        for (int i = 0; i <= 1000; i++) {
            for (int j = 0; j <= i; j++) {
                int x = 3 * (i - j), y = 4 * j;
                if (a > i || b > x + y) continue;
                mn = min(mn, i - a + (x + y - b));
            }
        }
        cout << mn << '\n';
    }
}