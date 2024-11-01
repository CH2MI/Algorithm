#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<vector<int>> adj, radj, scc;
vector<bool> visited;
stack<int> st;

void DFS(int n) {
    visited[n] = true;

    for (const auto& i : adj[n])
        if (!visited[i]) DFS(i);

    st.push(n);
}

void RDFS(int k, int n) {
    visited[n] = true;
    scc[k].push_back(n);

    for (const auto& i : radj[n])
        if (!visited[i]) RDFS(k, i);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int N, M;
    cin >> N >> M;
    adj.assign(N, vector<int>());
    radj.assign(N, vector<int>());

    for (int i = 0; i < M; i++) {
        int s, e;
        cin >> s >> e;
        adj[s - 1].push_back(e - 1);
        radj[e - 1].push_back(s - 1);
    }

    visited.assign(N, false);
    for (int i = 0; i < N; i++) {
        if (!visited[i]) DFS(i);
    }


    visited.assign(N, false);
    while (!st.empty()) {
        int n = st.top();
        st.pop();
        if (visited[n]) continue;
        scc.emplace_back();
        RDFS((int)scc.size() - 1, n);
    }

    if ((int)scc.size() == 1) cout << "Yes";
    else cout << "No";
}