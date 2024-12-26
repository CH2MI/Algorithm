#include <bits/stdc++.h>
using namespace std;

vector<int> v;
vector<vector<int>> adj;

void DFS(int cur, int x) {
    v[cur] += x;
    for (int& nxt : adj[cur]) DFS(nxt, v[cur]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    v.assign(n, 0);
    adj.assign(n, vector<int>());
    for (int i = 0; i < n; i++) {
        int s; cin >> s;
        if (s == -1) continue;
        adj[s - 1].push_back(i);
    }
    for (int i = 0; i < m; i++) {
        int s, w; cin >> s >> w;
        v[s - 1] += w;
    }
    DFS(0, 0);
    for (int& i : v) cout << i << ' ';
}