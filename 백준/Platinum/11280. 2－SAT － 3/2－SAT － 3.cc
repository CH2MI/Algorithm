#include <bits/stdc++.h>
using namespace std;

vector<int> visited, sn;
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;
    adj.assign(N << 1, vector<int>());
    radj.assign(N << 1, vector<int>());

    for (int i = 0; i < M; i++) {
        int s, e; cin >> s >> e;
        int a = s < 0, b = e < 0;
        s = abs(s); e = abs(e);
        adj[(s - 1) * 2 + !a].push_back((e - 1) * 2 + b);
        radj[(e - 1) * 2 + b].push_back((s - 1) * 2 + !a);

        adj[(e - 1) * 2 + !b].push_back((s - 1) * 2 + a);
        radj[(s - 1) * 2 + a].push_back((e - 1) * 2 + !b);
    }
    int n = N << 1;

    visited.assign(n, 0);
    for (int i = 0; i < n; i++) if (!visited[i]) DFS(i);
    visited.assign(n, 0);
    sn.assign(n, 0);
    int s = 0;
    for (; !st.empty(); st.pop()) if (!visited[st.top()]) RDFS(s++, st.top());

    bool f = 1;
    for (int i = 0; i < N; i++) {
        if (sn[i << 1] == sn[(i << 1) + 1]) {
            f = 0;
        }
    }
    cout << f;
}