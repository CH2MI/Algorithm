#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int N; cin >> N;
    long long mn = 1, mx = 1;
    for (int i = 0; i < N; i++) {
        long long a, b; cin >> a >> b;
        if (a > b) swap(a, b);
        mn = max(mn, a);
        mx = max(mx, b);
    }

    cout << mn * mx;
}
