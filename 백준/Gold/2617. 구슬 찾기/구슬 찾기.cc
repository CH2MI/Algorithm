#include <bits/stdc++.h>
using namespace std;

vector<int> visited;
vector<vector<int>> adj, radj;

int DFS(int cur) {
    if (visited[cur]) return 0;

    visited[cur] = 1;
    int cnt = 1;
    for (int& nxt : adj[cur]) cnt += DFS(nxt);
    return cnt;
}

int RDFS(int cur) {
    if (visited[cur]) return 0;

    visited[cur] = 1;
    int cnt = 1;
    for (int& nxt : radj[cur]) cnt += RDFS(nxt);
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;
    adj.assign(N, vector<int>());
    radj.assign(N, vector<int>());
    for (int i = 0; i < M; i++) {
        int s, e; cin >> s >> e;
        adj[s - 1].push_back(e - 1);
        radj[e - 1].push_back(s - 1);
    }

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        visited.assign(N, 0);
        if (DFS(i) > N / 2 + 1) {
            cnt++;
            continue;
        }
        visited.assign(N, 0);
        if (RDFS(i) > N / 2 + 1) cnt++;
    }
    cout << cnt;
}