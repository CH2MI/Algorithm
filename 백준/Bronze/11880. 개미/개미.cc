#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int T; cin >> T;
    while (T--) {
        long long a, b, c; cin >> a >> b >> c;
        cout << min({a * a + (b + c) * (b + c), b * b + (a + c) * (a + c), c * c + (a + b) * (a + b)}) << '\n';
    }
}
