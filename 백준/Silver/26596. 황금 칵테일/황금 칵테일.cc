#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    unordered_map<string, int> m;
    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        string k; int v;
        cin >> k >> v;
        m[k] += v;
    }

    bool f = false;
    for (const auto& [k1, v1] : m) {
        for (const auto& [k2, v2] : m) {
            if (k1 == k2) continue;

            if ((int)((double)v1 * 1.618) == v2) f = true;
        }
    }

    if (f) cout << "Delicious!";
    else cout << "Not Delicious...";
}
