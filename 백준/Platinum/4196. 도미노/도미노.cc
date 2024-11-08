#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<bool> visited;
vector<int> scc, indegree;
vector<vector<int>> adj, radj;
stack<int> st;

void DFS(int n) {
    visited[n] = 1;

    for (const auto& i : adj[n]) {
        if (!visited[i]) DFS(i);
    }

    st.push(n);
}

void RDFS(int s, int n) {
    visited[n] = 1;

    scc[n] = s;
    for (const auto& i : radj[n]) {
        if (!visited[i]) RDFS(s, i);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        int N, M; cin >> N >> M;

        adj.assign(N, vector<int>());
        radj.assign(N, vector<int>());
        scc.assign(N, 0);

        for (int i = 0; i < M; i++) {
            int s, e; cin >> s >> e;
            adj[s - 1].push_back(e - 1);
            radj[e - 1].push_back(s - 1);
        }

        visited.assign(N, 0);
        for (int i = 0; i < N; i++) {
            if (!visited[i]) DFS(i);
        }

        visited.assign(N, 0);
        int cnt = 0;
        while (!st.empty()) {
            int n = st.top(); st.pop();
            if (visited[n]) continue;
            RDFS(cnt++, n);
        }

        indegree.assign(cnt, 0);

        for (int i = 0; i < N; i++) {
            for (auto j : adj[i]) {
                if (scc[i] != scc[j]) {
                    indegree[scc[j]]++;
                }
            }
        }
        
        int ans = 0;
        for (const auto& i : indegree) if (!i) ans++;
        cout << ans << '\n';
    }
}