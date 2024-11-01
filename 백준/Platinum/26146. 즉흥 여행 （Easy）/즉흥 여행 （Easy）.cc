#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<vector<int>> adj, radj;
vector<bool> visited;
stack<int> st;

void DFS(int n) {
    visited[n] = true;

    for (const auto& i : adj[n])
        if (!visited[i]) DFS(i);

    st.push(n);
}

void RDFS(int n) {
    visited[n] = true;
    for (const auto& i : radj[n])
        if (!visited[i]) RDFS(i);
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
    int cnt = 0;
    while (!st.empty()) {
        int n = st.top(); st.pop();
        if (visited[n]) continue;
        cnt++;
        RDFS(n);
    }

    if (cnt == 1) cout << "Yes";
    else cout << "No";
}