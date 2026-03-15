#include <bits/stdc++.h>
using namespace std;

int N;
vector<vector<int>> adj;
vector<int> visited;

void dfs(int cur, int cnt) {
    visited[cur] = cnt;

    for (int nxt : adj[cur]) {
        if (visited[nxt] == -1) dfs(nxt, cnt + 1);
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int N, M, R; cin >> N >> M >> R;
    adj.assign(N, vector<int>());
    visited.assign(N, -1);

    for (int i = 0; i < M; i++) {
        int s, e; cin >> s >> e;
        adj[s - 1].push_back(e - 1);
        adj[e - 1].push_back(s - 1);
    }

    for (auto& v : adj) sort(v.begin(), v.end());

    dfs(R - 1, 0);
    for (int i : visited) cout << i << '\n';

}
