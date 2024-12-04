#include <bits/stdc++.h>
using namespace std;

int hashcnt, s;
unordered_map<string, int> hashmap;
vector<bool> visited;
vector<int> scc, indegree;
vector<long long> sum;
vector<vector<int>> adj, radj;
vector<set<int>> sadj;
stack<int> st;

int get(string& s) {
    if (hashmap.find(s) == hashmap.end()) hashmap.insert({s, hashcnt++}), adj.emplace_back(), radj.emplace_back();
    return hashmap[s];
}

void DFS(int n) {
    visited[n] = 1;

    for (int& i : adj[n]) {
        if (!visited[i]) DFS(i);
    }
    st.push(n);
}

void RDFS(int s, int n) {
    visited[n] = 1;
    scc[n] = s;
    for (int& i : radj[n]) {
        if (!visited[i]) RDFS(s, i);
    }
}

void TS() {
    queue<int> q;
    for (int i = 0; i < s; i++) {
        if (!indegree[i]) q.push(i);
    }

    while (!q.empty()) {
        int n = q.front(); q.pop();

        for (int i = 0; i < hashcnt; i++) {
            if (scc[i] != n) continue;
            for (int& j : adj[i]) {
                if (scc[i] != scc[j]) sum[j] += sum[i];
            }
        }
        for (const int& i : sadj[n]) {
            if (!(--indegree[i])) q.push(i);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    for (int i = 0; i < n; i++) {
        string name; cin >> name;
        int a = get(name);
        int m; cin >> m;
        for (int j = 0; j < m; j++) {
            cin >> name;
            int b = get(name);
            radj[a].push_back(b);
            adj[b].push_back(a);
        }
    }
    visited.assign(hashcnt, 0);
    for (int i = 0; i < hashcnt; i++)
        if (!visited[i]) DFS(i);

    visited.assign(hashcnt, 0);
    scc.assign(hashcnt, 0);
    while (!st.empty()) {
        int i = st.top(); st.pop();
        if (!visited[i]) {
            RDFS(s++, i);
        }
    }

    sadj.assign(s, set<int>());
    for (int i = 0; i < hashcnt; i++) {
        for (int& j : adj[i]) {
            int a = scc[i], b = scc[j];
            if (a == b) continue;
            sadj[a].insert(b);
        }
    }

    indegree.assign(s, 0);
    for (int i = 0; i < s; i++) {
        for (const int& j : sadj[i]) indegree[j]++;
    }
    sum.assign(hashcnt, 1);
    TS();

    string name; cin >> name;
    cout << sum[hashmap[name]];
}
