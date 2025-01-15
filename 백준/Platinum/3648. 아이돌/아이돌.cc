#include <bits/stdc++.h>
using namespace std;

int n, S, cnt;
vector<int> sn, dt;
vector<vector<int>> adj;
stack<int> st;

int DFS(int cur) {
    int ret = dt[cur] = cnt++;
    st.push(cur);

    for (int& nxt : adj[cur]) {
        if (dt[nxt] == -1) ret = min(ret, DFS(nxt));
        else if (sn[nxt] == -1) ret = min(ret, dt[nxt]);
    }

    if (ret == dt[cur]) {
        while (1) {
            int u = st.top(); st.pop();
            sn[u] = S;
            if (u == cur) break;
        }
        S++;
    }
    return ret;
}

bool SCC() {
    S = cnt = 0;
    sn = dt = vector(n << 1, -1);

    for (int i = 0; i < n << 1; i++) if (dt[i] == -1) DFS(i);

    for (int i = 0; i < n; i++) {
        if (sn[i << 1] == sn[(i << 1) + 1]) return 0;
    }

    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int m;
    while (cin >> n >> m) {
        adj.assign(n << 1, vector<int>());

        for (int i = 0; i < m; i++) {
            int s, e; cin >> s >> e;
            int a = s < 0, b = e < 0;
            adj[(abs(s) - 1 << 1) + !a].push_back((abs(e) - 1 << 1) + b);
            adj[(abs(e) - 1 << 1) + !b].push_back((abs(s) - 1 << 1) + a);
        }
        adj[1].push_back(0);

        if (SCC()) cout << "yes\n";
        else cout << "no\n";
    }
}