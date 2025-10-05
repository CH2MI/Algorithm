#include <bits/stdc++.h>
using namespace std;
 
typedef array<int, 3> ability;
 
int N;
 
vector<vector<int>> adj;
vector<int> visited;
 
int fight(ability& a, ability& b) {
    int winA = 0, winB = 0;
    for (int i = 0; i < 3; i++) {
        winA += a[i] >= b[i];
        winB += a[i] <= b[i];
    }
 
    if (winA > winB) return 1;
    if (winA < winB) return -1;
    return 0;
}
 
int DFS(int cur) {
    visited[cur] = 1;
 
    int ans = 1;
 
    for (int nxt : adj[cur]) {
        if (visited[nxt] == 2) continue;
        if (visited[nxt] == 1) return 0;
        ans &= DFS(nxt);
    }
    visited[cur] = 2;
 
    return ans;
}
 
vector<int> GetIndegreeZero() {
    vector<int> indegree(N);
    vector<int> ret;
    for (auto& i : adj) {
        for (int& j : i) {
            indegree[j]++;
        }
    }
 
    queue<int> q;
    for (int i = 0; i < N; i++) {
        if (!indegree[i]) {
            ret.push_back(i);
        }
    }
 
    return ret;
}
 
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
 
    cin >> N;
 
    vector<ability> v(N);
    vector<string> names(N);
 
    for (int i = 0; i < N; i++) {
        string S; int p, a, s;
        cin >> S >> p >> a >> s;
        names[i] = S;
        v[i] = {p, a, s};
    }
 
    adj.assign(N, vector<int>());
 
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int ans = fight(v[i], v[j]);
            if (ans == 1) adj[i].push_back(j);
            else if (ans == -1) adj[j].push_back(i);
        }
    }
    visited.assign(N, 0);
    auto ans = GetIndegreeZero();
    int ret = 1;
    for (int i : ans) {
        ret &= DFS(i);
    }
 
    if (!ret || ans.empty()) cout << "Paradoxe Absurdo";
    else {
        vector<string> name;
        for (int i : ans) name.push_back(names[i]);
        sort(name.begin(), name.end());
 
        for (auto& s : name) cout << s << '\n';
    }
}
