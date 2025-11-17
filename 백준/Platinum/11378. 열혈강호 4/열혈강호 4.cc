#include <bits/stdc++.h>
using namespace std;

constexpr int INF = (int)1e9;

int N, M, K;
vector<vector<int>> adj, capacity, flow;

int bfs(int source, int sink) {
    vector<int> parent(N + M + 2, -1);
    queue<int> q;

    parent[source] = source;
    q.push(source);

    while (!q.empty() && parent[sink] == -1) {
        int cur = q.front(); q.pop();

        for (int nxt : adj[cur]) {
            if (capacity[cur][nxt] - flow[cur][nxt] > 0 && parent[nxt] == -1) {
                parent[nxt] = cur;
                q.push(nxt);
            }
        }
    }

    if (parent[sink] == -1) return 0;

    for (int cur = sink; cur != source; cur = parent[cur]) {
        flow[parent[cur]][cur] += 1;
        flow[cur][parent[cur]] -= 1;
    }

    return 1;
}

int mf(int source, int sink) {
    int total_cnt = 0;

    for (int i = 0; i < N; i++) {
        if (bfs(source, sink)) total_cnt++;
        else break;
    }

    for (int i = 1; i <= N; i++) capacity[0][i] = INF;

    for (int i = 0; i < K; i++) {
        if (bfs(source, sink)) total_cnt++;
        else break;
    }


    return total_cnt;
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    cin >> N >> M >> K;

    adj.assign(N + M + 2, vector<int>());
    capacity.assign(N + M + 2, vector<int>(N + M + 2));
    flow.assign(N + M + 2, vector<int>(N + M + 2));

    for (int i = 1; i <= N; i++) {
        capacity[0][i] = 1;
        adj[0].push_back(i);
        adj[i].push_back(0);
    }

    for (int i = 1; i <= M; i++) {
        capacity[i + N][N + M + 1] = 1;
        adj[i + N].push_back(N + M + 1);
        adj[N + M + 1].push_back(i + N);
    }

    for (int s = 1; s <= N; s++) {
        int n; cin >> n;
        for (int i = 0; i < n; i++) {
            int e; cin >> e;
            capacity[s][e + N] = 1;
            adj[s].push_back(e + N);
            adj[e + N].push_back(s);
        }
    }

    cout << mf(0, N + M + 1);

}