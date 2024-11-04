#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

vector<bool> visited;
vector<vector<int>> adj, radj, scc;
stack<int> st;

void DFS(int n) {
    visited[n] = true;

    for (const auto& i : adj[n]) {
        if (!visited[i]) DFS(i);
    }
    st.push(n);
}

void RDFS(int s, int n) {
    visited[n] = true;
    scc[s].push_back(n);
    for (const auto& i : radj[n]) {
        if (!visited[i]) RDFS(s, i);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int V, E; cin >> V >> E;
    adj.assign(V, vector<int>());
    radj.assign(V, vector<int>());

    for (int i = 0; i < E; i++) {
        int s, e; cin >> s >> e;
        adj[s - 1].push_back(e - 1);
        radj[e - 1].push_back(s - 1);
    }

    visited.assign(V, false);
    for (int i = 0; i < V; i++)
        if (!visited[i]) DFS(i);

    visited.assign(V, false);
    int s = 0;
    while (!st.empty()) {
        int n = st.top(); st.pop();
        if (!visited[n]) {
            scc.emplace_back();
            RDFS(s++, n);
        }
    }

    cout << scc.size() << '\n';


    for (auto& i : scc) sort(i.begin(), i.end());
    sort(scc.begin(), scc.end());

    for (auto& i : scc) {
        for (const auto& j : i) cout << j + 1 << ' ';
        cout << "-1\n";
    }

}