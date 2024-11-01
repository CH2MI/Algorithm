#include <iostream>
#include <vector>
#include <stack>
#include <set>
using namespace std;

vector<int> scc, visited, indegree, outdegree;
vector<vector<int>> adj, radj;
vector<set<int>> dadj;
stack<int> st;

void DFS(int n) {
    visited[n] = true;

    for (const auto& i : adj[n]) if (!visited[i]) DFS(i);

    st.push(n);
}

void RDFS(int s, int n) {
    visited[n] = true;
    scc[n] = s;

    for (const auto& i : radj[n]) if (!visited[i]) RDFS(s, i);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int N, M; cin >> N >> M;
    adj.assign(N, vector<int>());
    radj.assign(N, vector<int>());
    scc.assign(N, -1);

    for (int i = 0; i < M; i++) {
        int s, e; cin >> s >> e;
        adj[s - 1].push_back(e - 1);
        radj[e - 1].push_back(s - 1);
    }

    // SCC를 한다.
    visited.assign(N, false);
    for (int i = 0; i < N; i++) if (!visited[i]) DFS(i);

    visited.assign(N, false);
    int cnt = 0;
    while (!st.empty()) {
        int i = st.top(); st.pop();
        if (!visited[i]) RDFS(cnt++, i);
    }

    // SCC를 바탕으로 DAG를 만든다.
    dadj.assign(cnt, set<int>());
    for (int i = 0; i < N; i++) {
        int n = scc[i];
        for (const auto& j : adj[i]) {
            if (n != scc[j]) dadj[n].insert(scc[j]);
        }
    }

    // DAG에서 진입, 진출 차수를 센다.
    indegree.assign(cnt, 0);
    outdegree.assign(cnt, 0);
    for (int i = 0; i < cnt; i++) {
        for (auto j : dadj[i]) {
            indegree[j]++;
            outdegree[i]++;
        }
    }

    int n = -1, incount = 0, outcount = 0;
    for (int i = 0; i < cnt; i++) {
        if (!indegree[i]) {
            n = i;
            incount++;
        }
        if (!outdegree[i]) {
            outcount++;
        }
    }

    // 진입, 진출 차수가 0인 노드가 각각 1개씩만 존재해야한다.
    vector<int> ans;
    if (incount == 1 && outcount == 1) {
        for (int i = 0; i < N; i++) if (scc[i] == n) ans.push_back(i);
    }

    cout << ans.size() << '\n';
    for (const auto& i : ans) cout << i + 1 << ' ';
}