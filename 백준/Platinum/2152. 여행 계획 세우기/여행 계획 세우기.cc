#include <bits/stdc++.h>
using namespace std;

int N, S;
vector<int> visited, sn, sv, c, v;
vector<vector<int>> adj, radj, sadj;
stack<int> st;

void DFS(int n) {
    visited[n] = 1;

    for (int& i : adj[n]) if (!visited[i]) DFS(i);

    st.push(n);
}

void RDFS(int s, int n) {
    visited[n] = 1;
    sn[n] = s;

    for (int& i : radj[n]) if (!visited[i]) RDFS(s, i);
}

void GetSCC() {
    visited.assign(N, 0);
    for (int i = 0; i < N; i++) if (!visited[i]) DFS(i);

    S = 0;
    visited.assign(N, 0);
    sn.assign(N, 0);
    for (; !st.empty(); st.pop()) if (!visited[st.top()]) RDFS(S++, st.top());
}

void Topology_sort(int s) {
    vector<int> in(S), isCount(S);
    c.assign(S, 0);
    sadj.assign(S, vector<int>());
    for (int i = 0; i < N; i++) {
        c[sn[i]]++;
        for (int& j : adj[i]) if (sn[i] != sn[j]) sadj[sn[i]].push_back(sn[j]);
    }
    for (int i = 0; i < S; i++) for (int& j : sadj[i]) ++in[j];
    queue<int> q;
    for (int i = 0; i < S; i++) if (!in[i]) q.push(i);
    v.assign(S, 0);
    while (!q.empty()) {
        auto n = q.front(); q.pop();

        if (sn[s] == n) isCount[n] = 1;
        if (isCount[n]) v[n] += c[n];

        for (int& i : sadj[n]) {
            if (isCount[n]) v[i] = max(v[i], v[n]), isCount[i] = 1;
            if (!--in[i]) q.push(i);
        }
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

    int M, s, t; cin >> N >> M >> s >> t;

    adj.assign(N, vector<int>());
    radj.assign(N, vector<int>());
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        adj[a - 1].push_back(b - 1);
        radj[b - 1].push_back(a - 1);
    }

    GetSCC();
    Topology_sort(s - 1);
    cout << v[sn[t - 1]];
}