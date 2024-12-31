#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int maxlevel;
vector<vector<array<ll, 2>>> adj, parent;
vector<ll> level;

void DFS(ll p, ll cur, ll dist) {
    level[cur] = level[p] + 1;
    parent[cur][0][0] = p;
    parent[cur][0][1] = dist;

    for (int i = 1; i <= maxlevel; i++) {
        parent[cur][i][0] = parent[parent[cur][i - 1][0]][i - 1][0];
        parent[cur][i][1] = parent[parent[cur][i - 1][0]][i - 1][1] + parent[cur][i - 1][1];
    }

    for (auto& [nxt, d] : adj[cur]) if (nxt != p) DFS(cur, nxt, d);
}

array<ll, 2> LCA(ll a, ll b) {
    if (level[a] < level[b]) swap(a, b);
    ll diff = level[a] - level[b];

    ll sum = 0;
    for (int i = 0; diff; i++) {
        if (diff & 1) sum += parent[a][i][1], a = parent[a][i][0];
        diff >>= 1;
    }

    if (a == b) return {sum, a};

    for (int i = maxlevel; i >= 0; i--) {
        if (parent[a][i][0] != parent[b][i][0]) {
            sum += parent[a][i][1] + parent[b][i][1];
            a = parent[a][i][0];
            b = parent[b][i][0];
        }
    }
    return {sum + parent[a][0][1] + parent[b][0][1], parent[a][0][0]};
}

ll query(ll a, ll b, ll k) {
    ll lca = LCA(a, b)[1];
    ll diff = level[a] - level[lca];

    ll ret = a;
    if (--k == -1) return a;
    if (k > diff) {
        k = level[b] - level[lca] - (k - diff);
        ret = b;
    }

    for (int i = 0; k; i++) {
        if (k & 1) ret = parent[ret][i][0];
        k >>= 1;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    maxlevel = (int)log2(N);
    adj.assign(N + 1, vector<array<ll, 2>>());
    parent.assign(N + 1, vector(maxlevel + 1, array<ll, 2>()));
    level.assign(N + 1, 0);

    for (int i = 0; i < N - 1; i++) {
        ll s, e, d; cin >> s >> e >> d;
        adj[s].push_back({e, d});
        adj[e].push_back({s, d});
    }
    DFS(0, 1, 0);

    int M; cin >> M;
    for (int i = 0; i < M; i++) {
        int q; cin >> q;
        if (q == 1) {
            ll u, v; cin >> u >> v;
            cout << LCA(u, v)[0] << '\n';
        }
        else {
            ll u, v, k; cin >> u >> v >> k;
            cout << query(u, v, k) << '\n';
        }
    }
}
