#include <bits/stdc++.h>
using namespace std;

int N;
vector<array<int, 3>> edge1, edge2;
vector<int> parent;

int Find(int x) {
    if (parent[x] == -1) return x;
    return parent[x] = Find(parent[x]);
}

bool Union(int a, int b) {
    a = Find(a);
    b = Find(b);

    if (a == b) return false;

    if (a < b) parent[b] = a;
    else parent[a] = b;
    return true;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int M; cin >> N >> M;
    edge1.reserve(M); edge2.reserve(M);
    parent.assign(N, -1);

    for (int i = 0; i < M; i++) {
        int s, e, w, d; cin >> s >> e >> w >> d;

        if (d) edge1.push_back({w, s - 1, e - 1});
        else edge2.push_back({w, s - 1, e - 1});
    }

    for (const auto& [w, s, e] : edge1) {
        Union(s, e);
    }

    sort(edge2.begin(), edge2.end(), greater());

    int sum = 0;

    for (const auto& [w, s, e] : edge2) {
        if (!Union(s, e)) sum += w;
    }

    cout << sum;
}
