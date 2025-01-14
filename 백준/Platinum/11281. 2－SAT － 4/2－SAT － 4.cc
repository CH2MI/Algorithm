#include <bits/stdc++.h>
using namespace std;

int N, S, d;
vector<int> dt, sn;
vector<vector<int>> adj;
stack<int> st;

int DFS(int cur) {
    int ret = dt[cur] = d++;
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
        ++S;
    }
    return ret;
}

int SCC() {
    sn = dt = vector(N << 1, -1);
    S = d = 0;
    for (int i = 0; i < N << 1; i++) if (dt[i] == -1) DFS(i);
    for (int i = 0; i < N; i++) {
        if (sn[i << 1] == sn[(i << 1) + 1]) return 0;
    }

    vector<array<int, 2>> v(N << 1);
    for (int i = 0; i < N << 1; i++) v[i][0] = -sn[i], v[i][1] = i;
    sort(v.begin(), v.end());

    vector ans(N, -1);
    for (int i = 0; i < N << 1; i++) {
        int u = v[i][1] / 2, isTrue = v[i][1] % 2 == 0;
        if (ans[u] != -1) continue;
        ans[u] = !isTrue;
    }

    cout << 1 << '\n';
    for (int& i : ans) cout << i << ' ';

    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int M; cin >> N >> M;
    adj.assign(N << 1, vector<int>());

    for (int i = 0; i < M; i++) {
        int s, e; cin >> s >> e;
        int a = s < 0, b = e < 0;
        adj[(abs(s) - 1) * 2 + !a].push_back((abs(e) - 1) * 2 + b);
        adj[(abs(e) - 1) * 2 + !b].push_back((abs(s) - 1) * 2 + a);
    }

    if (!SCC()) cout << 0;
}