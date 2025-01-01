#include <bits/stdc++.h>
using namespace std;

vector<int> visited, scc, in;
vector<vector<int>> adj, radj;
stack<int> st;

void DFS(int n) {
    visited[n] = 1;

    for (auto& i : adj[n]) if (!visited[i]) DFS(i);

    st.push(n);
}

void RDFS(int s, int n) {
    visited[n] = 1;
    scc[n] = s;

    for (auto& i : radj[n]) if (!visited[i]) RDFS(s, i);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        int N, M; cin >> N >> M;
        adj.assign(N, vector<int>());
        radj.assign(N, vector<int>());
        scc.assign(N, 0);

        for (int i = 0; i < M; i++) {
            int s, e; cin >> s >> e;
            adj[s].push_back(e);
            radj[e].push_back(s);
        }

        visited.assign(N, 0);
        for (int i = 0; i < N; i++) if (!visited[i]) DFS(i);

        visited.assign(N, 0);
        int s = 0;
        while (!st.empty()) {
            int n = st.top(); st.pop();
            if (!visited[n]) {
                RDFS(s++, n);
            }
        }
        in.assign(s, 0);
        for (int i = 0; i < N; i++) {
            for (int& j : adj[i]) {
                if (scc[i] != scc[j]) {
                    in[scc[j]]++;
                }
            }
        }

        int ans = -1, cnt = 0;
        for (int i = 0; i < s; i++) {
            if (!in[i]) ans = i, cnt++;
        }
        if (cnt == 1) {
            for (int i = 0; i < N; i++) if (scc[i] == ans) cout << i << '\n';
        }
        else cout << "Confused\n";
        cout << '\n';
    }
}
