#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int N, M;
    cin >> N >> M;
    vector<int> v(N);
    for (int& i : v) cin >> i;
    sort(v.begin(), v.end());

    unordered_map<int, int> m;
    for (int i = 0; i < N; i++) {
        if (m.find(v[i]) == m.end()) m[v[i]] = i;
    }

    for (int i = 0; i < M; i++) {
        int q; cin >> q;
        if (m.find(q) == m.end()) cout << -1 << '\n';
        else cout << m[q] << '\n';
    }
}