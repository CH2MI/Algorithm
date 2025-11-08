#include <bits/stdc++.h>
using namespace std;

int N;
vector<vector<int>> adj;

int bfs(int s, int e) {
    vector<int> visited(N);
    queue<array<int, 2>> q;
    q.push({s, 0});

    while (!q.empty()) {
        auto [cur, cnt] = q.front(); q.pop();

        if (visited[cur]) continue;
        if (cur == e) return cnt;

        visited[cur] = 1;

        for (int nxt : adj[cur]) {
            q.push({nxt, cnt + 1});
        }
    }

    return -1;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    cin >> N;
    int S, E; cin >> S >> E;
    adj.assign(N, vector<int>());
    int M; cin >> M;
    for (int i = 0; i < M; i++) {
        int s, e; cin >> s >> e;
        adj[s - 1].push_back(e - 1);
        adj[e - 1].push_back(s - 1);
    }

    cout << bfs(S - 1, E - 1);
}
