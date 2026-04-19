#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int a, b, c; cin >> a >> b >> c;

    if (a + b < 2 * c) cout << a + b;
    else cout << a + b - 2 * c;

}
