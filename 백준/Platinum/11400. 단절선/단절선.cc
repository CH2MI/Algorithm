#include <bits/stdc++.h>
using namespace std;

int cnt = 0;
vector<int> dt;
vector<array<int, 2>> ans;
vector<vector<int>> adj;

int DFS(int pre, int cur) {
    int mn = dt[cur] = ++cnt;

    for (int& nxt : adj[cur]) {
        if (nxt == pre) continue;
        if (!dt[nxt]) {
            int s = DFS(cur, nxt);
            if (s > dt[cur]) {
                if (cur < nxt) ans.push_back({cur, nxt});
                else ans.push_back({nxt, cur});
            }
            mn = min(mn, s);
        }
        else mn = min(mn, dt[nxt]);
    }
    return mn;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int V, E; cin >> V >> E;
    adj.assign(V, vector<int>());
    dt.assign(V, 0);

    for (int i = 0; i < E; i++) {
        int s, e; cin >> s >> e;
        adj[s - 1].push_back(e - 1);
        adj[e - 1].push_back(s - 1);
    }
    for (int i = 0; i < V; i++) {
        if (!dt[i]) DFS(-1, i);
    }
    sort(ans.begin(), ans.end());

    cout << ans.size() << '\n';
    for (auto& [s, e] : ans) cout << s + 1 << ' ' << e + 1 << '\n';
}