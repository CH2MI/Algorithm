#include <bits/stdc++.h>
using namespace std;

vector<int> parent;

int Find(int x) {
    if (parent[x] == -1) return x;
    return parent[x] = Find(parent[x]);
}

void Union(int a, int b) {
    if (b >= parent.size()) return;
    a = Find(a);
    b = Find(b);

    if (a == b) return;

    if (a < b) parent[a] = b;
    else parent[b] = a;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N, M, K; cin >> N >> M >> K;

    vector<int> v(M);
    for (int& i : v) cin >> i;
    sort(v.begin(), v.end());
    parent.assign(M, -1);

    for (int i = 0; i < K; i++) {
        int a; cin >> a;

        int x = lower_bound(v.begin(), v.end(), a + 1) - v.begin();
        int p = Find(x);
        cout << v[p] << '\n';
        Union(p, p + 1);

    }
}