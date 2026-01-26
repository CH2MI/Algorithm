#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int cnt = 0;
    int N, K; cin >> N >> K;
    vector<int> v(N);
    for (int& i : v) cin >> i;

    for (int i = 1; i < v.size(); i++) {
        int loc = i - 1;
        int newItem = v[i];

        while (0 <= loc && newItem < v[loc]) {
            v[loc + 1] = v[loc];
            if (++cnt == K) cout << v[loc];
            --loc;
        }
        if (loc + 1 != i) {
            v[loc + 1] = newItem;
            if (++cnt == K) cout << newItem;
        }

    }

    if (cnt < K) cout << -1;
}
