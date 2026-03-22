#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int T; cin >> T;
    while (T--) {
        int V, E; cin >> V >> E;
        cout << E - V + 2 << '\n';
    }
}
