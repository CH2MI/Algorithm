#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int E, S, M; cin >> E >> S >> M;

    int cnt = 1;
    int e = 1, s = 1, m = 1;
    while (E != e || S != s || M != m) {
        if (++e == 16) e = 1;
        if (++s == 29) s = 1;
        if (++m == 20) m = 1;
        ++cnt;
    }
    cout << cnt;
}
