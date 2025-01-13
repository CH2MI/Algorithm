#include <bits/stdc++.h>
using namespace std;

int cnt = 0;
vector<int> dt, cut;
vector<vector<int>> adj;

int DFS(int cur, bool root) {
    dt[cur] = ++cnt;
    int ret = dt[cur], child = 0;

    for (int& nxt : adj[cur]) {
        if (!dt[nxt]) {
            ++child;
            int s = DFS(nxt, 0);
            if (!root && dt[cur] <= s) cut[cur] = 1;
            ret = min(ret, s);
        }
        else ret = min(ret, dt[nxt]);
    }
    if (root) cut[cur] = (child >= 2);
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int V, E; cin >> V >> E;
    adj.assign(V, vector<int>());

    for (int i = 0; i < E; i++) {
        int s, e; cin >> s >> e;
        adj[s - 1].push_back(e - 1);
        adj[e - 1].push_back(s - 1);
    }

    dt.assign(V, 0);
    cut.assign(V, 0);
    for (int i = 0; i < V; i++) if (!dt[i]) DFS(i, 1);

    vector<int> ans;
    for (int i = 0; i < V; i++) if (cut[i]) ans.push_back(i + 1);
    cout << ans.size() << '\n';
    for (int& i : ans) cout << i << ' ';
}