#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N, Q; cin >> N >> Q;
    vector<set<int>> v(N);

    for (int i = 0; i < N; i++) {
        int n; cin >> n;
        for (int j = 0; j < n; j++) {
            int s; cin >> s;
            v[i].insert(s);
        }
    }

    for (int i = 0; i < Q; i++) {
        int q; cin >> q;
        if (q == 1) {
            int a, b; cin >> a >> b;
            if (v[a - 1].size() < v[b - 1].size()) swap(v[a - 1], v[b - 1]);
            for (int j : v[b - 1]) v[a - 1].insert(j);
            v[b - 1] = set<int>();
        }
        else {
            int a; cin >> a;
            cout << v[a - 1].size() << '\n';
        }
    }
}