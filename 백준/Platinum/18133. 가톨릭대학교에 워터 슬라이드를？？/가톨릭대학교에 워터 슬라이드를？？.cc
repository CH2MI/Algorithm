#include <bits/stdc++.h>
using namespace std;

int N, S;
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

void GetScc() {
    scc.assign(N, 0);

    visited.assign(N, 0);
    for (int i = 0; i < N; i++) if (!visited[i]) DFS(i);

    visited.assign(N, 0);
    S = 0;
    while (!st.empty()) {
        int n = st.top(); st.pop();
        if (!visited[n]) {
            RDFS(S++, n);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int M; cin >> N >> M;

    adj.assign(N, vector<int>());
    radj.assign(N, vector<int>());
    for (int i = 0; i < M; i++) {
        int s, e; cin >> s >> e;
        adj[s - 1].push_back(e - 1);
        radj[e - 1].push_back(s - 1);
    }

    GetScc();

    in.assign(S, 0);
    for (int i = 0; i < N; i++) {
        for (int& j : adj[i]) {
            if (scc[i] != scc[j]) {
                in[scc[j]]++;
            }
        }
    }
    int cnt = 0;
    for (int& i : in) if (!i) ++cnt;
    cout << cnt;
}
