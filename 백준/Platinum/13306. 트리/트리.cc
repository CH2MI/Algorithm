#include <bits/stdc++.h>
using namespace std;

vector<int> parent;

int Find(int x) {
    if (parent[x] == -1) return x;
    return parent[x] = Find(parent[x]);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N, Q; cin >> N >> Q;
    parent.assign(N, -1);


    for (int i = 1; i < N; i++) {
        int p; cin >> p;
        parent[i] = p - 1;
    }
    vector<int> replica(parent);
    vector<array<int, 3>> querys(N - 1 + Q);
    for (auto& [q, a, b] : querys) {
        cin >> q >> a;
        if (q) cin >> b;
        else parent[a - 1] = -1;
    }

    vector<int> ans; ans.reserve(Q);

    for (auto itr = querys.rbegin(); itr != querys.rend(); ++itr) {
        auto [q, a, b] = *itr;
        if (q) {
            ans.push_back(Find(a - 1) == Find(b - 1));
        }
        else {
            parent[a - 1] = replica[a - 1];
        }
    }

    for (auto itr = ans.rbegin(); itr != ans.rend(); ++itr) {
        cout << (*itr ? "YES" : "NO") << '\n';
    }
}