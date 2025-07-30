#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> parent;
vector<long long> v;
vector<vector<int>> adj;

void DFS(int pre, int cur) {
    parent[cur] = pre;
    for (auto& nxt : adj[cur]) {
        if (nxt == pre) continue;
        DFS(cur, nxt);
    }
}

void DFS(int pre, int cur, long long x) {
    long long d = min(v[cur], x);
    v[cur] += d;
    long long r = x - d;
    if (adj[cur].size() > 1) {
        if (!cur) r /= adj[cur].size();
        else r /= adj[cur].size() - 1;
    }
    if (!r) return;

    for (auto& nxt : adj[cur]) {
        if (nxt == pre) continue;
        DFS(cur, nxt, r);
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int Q; cin >> N >> Q;
    adj.assign(N, vector<int>());
    for (int i = 0; i < N - 1; i++) {
        int s, e; cin >> s >> e;
        adj[s - 1].push_back(e - 1);
        adj[e - 1].push_back(s - 1);
    }
    v.assign(N, 0);
    for (auto& i : v) cin >> i;

    parent.assign(N, -1);
    DFS(-1, 0);

    for (int i = 0; i < Q; i++) {
        int q; cin >> q;
        if (q == 1) {
            int u, x; cin >> u >> x;
            DFS(parent[u - 1], u - 1, x);
        }
        else {
            int u; cin >> u;
            cout << v[u - 1] << '\n';
        }
    }
}