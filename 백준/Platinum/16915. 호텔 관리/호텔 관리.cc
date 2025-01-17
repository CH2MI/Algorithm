#include <bits/stdc++.h>
using namespace std;

int N, M, S, cnt;
vector<int> dt, sn;
vector<vector<int>> adj;
stack<int> st;

void Input() {
    cin >> N >> M;
    vector<int> on(N);
    for (int& i : on) cin >> i;

    vector<vector<int>> v(N);
    for (int i = 0; i < M; i++) {
        int K; cin >> K;
        while (K--) {
            int k; cin >> k;
            v[k - 1].push_back(i);
        }
    }

    adj.assign(M << 1, vector<int>());
    for (int i = 0; i < N; i++) {
        int s = v[i][0], e = v[i][1];
        if (!on[i]) {
            adj[s * 2 + 1].push_back(e * 2);
            adj[e * 2 + 1].push_back(s * 2);
            adj[s * 2].push_back(e * 2 + 1);
            adj[e * 2].push_back(s * 2 + 1);
        }
        else {
            adj[s * 2].push_back(e * 2);
            adj[e * 2].push_back(s * 2);
            adj[s * 2 + 1].push_back(e * 2 + 1);
            adj[e * 2 + 1].push_back(s * 2 + 1);
        }
    }
}

int DFS(int cur) {
    int ret = dt[cur] = cnt++;
    st.push(cur);

    for (int& nxt : adj[cur]) {
        if (dt[nxt] == -1) ret = min(ret, DFS(nxt));
        else if (sn[nxt] == -1) ret = min(ret, dt[nxt]);
    }

    if (dt[cur] == ret) {
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
    dt = sn = vector(M << 1, -1);
    for (int i = 0; i < M << 1; i++) if (dt[i] == -1) DFS(i);

    for (int i = 0; i < M; i++) {
        if (sn[i * 2] == sn[i * 2 + 1]) return 0;
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Input();

    cout << SCC();
}