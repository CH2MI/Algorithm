#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> parent;
vector<vector<array<int, 2>>> mst;
vector<array<int, 3>> edges;

int Find(int x) {
    if (parent[x] == -1) return x;
    return parent[x] = Find(parent[x]);
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);

    if (a == b) return;

    if (a < b) parent[b] = a;
    else parent[a] = b;
}

int DFS(int tg, int pre, int cur, int w) {
    if (tg == cur) return w;

    for (auto [nxt, weight] : mst[cur]) {
        if (nxt == pre) continue;
        int ret = DFS(tg, cur, nxt, weight);
        if (ret != INT_MAX) return min(weight, ret);
    }
    return INT_MAX;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int M, K; cin >> N >> M >> K;

    edges.assign(M, array<int, 3>());

    for (int i = 0; i < M; i++) {
        int s, e, w; cin >> s >> e >> w;
        edges[i] = {-w, s - 1, e - 1};
    }
    sort(edges.begin(), edges.end());

    parent.assign(N, -1);
    mst.assign(N, vector<array<int, 2>>());

    for (auto [w, s, e] : edges) {
        if (Find(s) == Find(e)) continue;
        mst[s].push_back({e, -w});
        mst[e].push_back({s, -w});
        Union(s, e);
    }

    for (int i = 0; i < K; i++) {
        int s, e; cin >> s >> e;
        cout << DFS(e - 1, -1, s - 1, INT_MAX) << '\n';
    }
}
