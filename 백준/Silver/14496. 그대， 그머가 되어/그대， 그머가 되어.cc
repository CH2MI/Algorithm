#include <bits/stdc++.h>
using namespace std;

int N;
vector<vector<int>> adj;

int bfs(int s, int e) {
    vector<int> visited(N);
    queue<array<int, 2>> q; q.push({0, s});

    while (!q.empty()) {
        auto [dist, cur] = q.front(); q.pop();

        if (cur == e) return dist;
        if (visited[cur]) continue;
        visited[cur] = 1;

        for (int nxt : adj[cur]) q.push({dist + 1, nxt});
    }

    return -1;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int S, E; cin >> S >> E;
    int M; cin >> N >> M;
    adj.assign(N, vector<int>());

    for (int i = 0; i < M; i++) {
        int s, e; cin >> s >> e;
        adj[s - 1].push_back(e - 1);
        adj[e - 1].push_back(s - 1);
    }

    cout << bfs(S - 1, E - 1);
}

