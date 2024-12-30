#include <bits/stdc++.h>
using namespace std;

int maxlevel;
vector<int> level;
vector<vector<array<int, 2>>> adj, parent;

int LCA(int a, int b) {
    if (level[a] < level[b]) swap(a, b);
    int diff = level[a] - level[b];

    int sum = 0;
    for (int i = 0; diff; i++) {
        if (diff & 1) sum += parent[a][i][1], a = parent[a][i][0];
        diff >>= 1;
    }

    if (a == b) return sum;

    for (int i = maxlevel; i >= 0; i--) {
        if (parent[a][i][0] != parent[b][i][0]) {
            sum += parent[a][i][1] + parent[b][i][1];
            a = parent[a][i][0];
            b = parent[b][i][0];
        }
    }
    return sum + parent[a][0][1] + parent[b][0][1];
}

void DFS(int p, int cur, int dist) {
    level[cur] = level[p] + 1;
    parent[cur][0] = {p, dist};

    for (int i = 1; i <= maxlevel; i++) {
        parent[cur][i][0] = parent[parent[cur][i - 1][0]][i - 1][0];
        parent[cur][i][1] = parent[parent[cur][i - 1][0]][i - 1][1] + parent[cur][i - 1][1];
    }

    for (auto& [nxt, d] : adj[cur]) if (nxt != p) DFS(cur, nxt, d);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    maxlevel = (int)log2(N);
    adj.assign(N + 1, vector<array<int, 2>>());
    parent.assign(N + 1, vector<array<int, 2>>(maxlevel + 1, array<int, 2>()));
    level.assign(N + 1, 0);

    for (int i = 0; i < N - 1; i++) {
        int s, e, d; cin >> s >> e >> d;
        adj[s].push_back({e, d});
        adj[e].push_back({s, d});
    }

    DFS(0, 1, 0);

    int M; cin >> M;
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        cout << LCA(a, b) << '\n';
    }
}
