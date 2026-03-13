#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N; cin >> N;
    vector<int> v(N);
    for (int& i : v) cin >> i;

    for (int i = 1; i <= 10e6; i++) {
        unordered_map<int, int> m;
        for (int j : v) m[j % i]++;

        if (m.size() == v.size()) {
            cout << i << '\n';
            return;
        }
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int N; cin >> N;
    while (N--) {
        solve();
    }
}
