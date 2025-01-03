#include <bits/stdc++.h>
using namespace std;

int N, S;
vector<int> visited, sn, v, sv, parent;
vector<set<int>> sadj;
vector<vector<int>> adj, radj;
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
    vector<int> in(S), start(S);
    sv.assign(S, 0);
    sadj.assign(S, set<int>());
    for (int i = 0; i < N; i++) {
        sv[sn[i]] += v[i];
        for (int& j : adj[i]) {
            if (sn[i] != sn[j]) sadj[sn[i]].insert(sn[j]);
        }
    }
    for (int i = 0; i < S; i++) {
        for (const int& j : sadj[i]) ++in[j];
    }
    queue<int> q;
    for (int i = 0; i < S; i++) {
        if (!in[i]) q.push(i);
    }
    parent.assign(S, 0);
    while (!q.empty()) {
        auto n = q.front(); q.pop();

        if (sn[s] == n) start[n] = 1;
        if (start[n]) parent[n] += sv[n];

        // 여기 시간 초과 원인!!!!
        for (const int& i : sadj[n]) {
            if (start[n]) parent[i] = max(parent[i], parent[n]), start[i] = 1;
            if (!--in[i]) {
                q.push(i);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int M; cin >> N >> M;
    v.assign(N, 0);
    adj.assign(N, vector<int>());
    radj.assign(N, vector<int>());
    for (int i = 0; i < M; i++) {
        int s, e; cin >> s >> e;
        adj[s - 1].push_back(e - 1);
        radj[e - 1].push_back(s - 1);
    }
    for (int& i : v) cin >> i;
    GetSCC();

    int s, p; cin >> s >> p;
    vector<int> res(N);
    for (int i = 0; i < p; i++) {
        int a; cin >> a; res[a - 1] = 1;
    }

    Topology_sort(s - 1);

    int mx = 0;
    for (int i = 0; i < N; i++) {
        if (res[i]) mx = max(mx, parent[sn[i]]);
    }
    cout << mx;
}
