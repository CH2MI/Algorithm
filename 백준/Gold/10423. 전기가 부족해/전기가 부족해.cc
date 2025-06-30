#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> stations;
vector<vector<array<int, 2>>> adj;

int prim() {
    vector<int> visited(N, -1);
    priority_queue<array<int, 2>> pq;
    for (int& i : stations) {
        for (auto& [u, w] : adj[i - 1]) pq.push({-w, u});
        visited[i - 1] = 0;
    }
    int cnt = (int)stations.size();
    while (!pq.empty()) {
        auto [dist, cur] = pq.top(); pq.pop();

        if (visited[cur] != -1) continue;

        visited[cur] = -dist;

        if (++cnt == N) return accumulate(visited.begin(), visited.end(), 0);

        for (auto& [nxt, w] : adj[cur]) {
            pq.push({-w, nxt});
        }
    }

    return 0;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int M, K; cin >> N >> M >> K;

    stations.assign(K, 0);
    for (auto& i : stations) cin >> i;

    adj.assign(N, vector<array<int, 2>>());
    for (int i = 0; i < M; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u - 1].push_back({v - 1, w});
        adj[v - 1].push_back({u - 1, w});
    }

    cout << prim();
}