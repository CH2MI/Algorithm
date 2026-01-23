#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int a, b, n, k; cin >> a >> b >> n >> k;

    int cnt = (k - 1) / n + 1;

    cout << (cnt - 1) / b + 1 << ' ' << (cnt - 1) % b + 1;
}
