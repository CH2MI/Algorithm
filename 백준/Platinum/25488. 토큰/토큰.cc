#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int cnt = 0, scccount = 0;
vector<int> num, low, scc;
vector<bool> visited;
vector<vector<int>> adj;
stack<int> st;

void DFS(int cur) {
    visited[cur] = 1;
    st.push(cur);
    num[cur] = low[cur] = ++cnt;
    for (auto nxt : adj[cur]) {
        if (!num[nxt]) {
            DFS(nxt);
            low[cur] = min(low[cur], low[nxt]);
        }
        else if (visited[nxt]){
            low[cur] = min(low[cur], num[nxt]);
        }
    }

    if (num[cur] == low[cur]) {
        while (!st.empty()) {
            int n = st.top(); st.pop();
            visited[n] = 0;
            scc[n] = scccount;
            if (cur == n) break;
        }
        scccount++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int N, M; cin >> N >> M;
    num.assign(N, 0);
    low.assign(N, 0);
    visited.assign(N, 0);
    scc.assign(N, 0);
    adj.assign(N, vector<int>());
    for (int i = 0; i < M; i++) {
        int s, e; cin >> s >> e;
        adj[s - 1].push_back(e - 1);
    }

    for (int i = 0; i < N; i++) {
        if (!num[i]) DFS(i);
    }

    int P; cin >> P;
    vector<int> count(scccount);
    for (int i = 0; i < P; i++) {
        int n; cin >> n;
        count[scc[n - 1]]++;
    }
    for (int i = 0; i < P; i++) {
        int n; cin >> n;
        count[scc[n - 1]]--;
    }
    int i = 0;
    for (; i < scccount; i++) {
        if (count[i]) break;
    }
    if (i == scccount) cout << "YES";
    else cout << "NO";
}