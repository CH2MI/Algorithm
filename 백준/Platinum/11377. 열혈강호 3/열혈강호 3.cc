#include <bits/stdc++.h>
using namespace std;

int N, M, K;
vector<int> parent;
vector<vector<int>> adj, flow;

int BFS() {
    parent.assign(N + M + 2, -1);

    queue<int> q;
    q.push(0);
    parent.front() = 0;
    while (!q.empty() && parent.back() == -1) {
        int cur = q.front();
        q.pop();

        for (int nxt = 0; nxt < N + M + 2; nxt++) {
            if (adj[cur][nxt] - flow[cur][nxt] > 0 && parent[nxt] == -1) {
                parent[nxt] = cur;
                q.push(nxt);
            }
        }
    }
    if (parent.back() == -1) return 0;

    for (int cur = N + M + 1; cur; cur = parent[cur]) {
        flow[parent[cur]][cur] += 1;
        flow[cur][parent[cur]] -= 1;
    }

    return 1;
}

int network_flow() {
    int total_flow = 0;

    while (BFS()) {
        total_flow++;
    }

    for (int i = 1; i <= N; i++) {
        flow[0][i] = 0;
    }

    for (int i = 0; i < K; i++) {
        if (BFS()) total_flow++;
        else break;
    }

    return total_flow;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    cin >> N >> M >> K;
    adj.assign(N + M + 2, vector<int>(N + M + 2));
    flow.assign(N + M + 2, vector<int>(N + M + 2));

    for (int i = 1; i <= N; i++) {
        adj[0][i] = 1;
        int k; cin >> k;
        for (int j = 0; j < k; j++) {
            int a; cin >> a;
            adj[i][N + a] = 1;
        }
    }

    for (int i = N + 1; i < N + M + 1; i++) {
        adj[i][N + M + 1] = 1;
    }

    cout << network_flow();
}