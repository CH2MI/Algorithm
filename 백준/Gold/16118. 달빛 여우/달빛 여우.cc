#include <bits/stdc++.h>
using namespace std;

constexpr int INF = (int)1e9;

int N, M;
vector<vector<array<int, 2>>> adj;
vector<int> fox;
vector<array<int, 2>> wolf;

void dijkstra1() {
    fox.assign(N, INF);

    priority_queue<array<int, 2>> pq;
    pq.push({0, 0});
    fox[0] = 0;

    while (!pq.empty()) {
        auto [cur_dist, cur_node] = pq.top(); pq.pop();
        cur_dist = -cur_dist;

        if (fox[cur_node] != cur_dist) continue;

        for (const auto& [nxt_node, dist] : adj[cur_node]) {
            int nxt_dist = cur_dist + dist * 2;
            if (nxt_dist < fox[nxt_node]) {
                fox[nxt_node] = nxt_dist;
                pq.push({-nxt_dist, nxt_node});
            }
        }
    }
}

void dijkstra2() {
    wolf.assign(N, {INF, INF});

    priority_queue<array<int, 3>> pq;
    pq.push({0, 0, 1});
    wolf[0][1] = 0;

    while (!pq.empty()) {
        auto [cur_dist, cur_node, dash] = pq.top(); pq.pop();
        cur_dist = -cur_dist;

        if (wolf[cur_node][dash] != cur_dist) continue;

        for (const auto& [nxt_node, dist] : adj[cur_node]) {
            int nxt_dist = cur_dist + (dist << (2 * !dash));
            if (nxt_dist < wolf[nxt_node][!dash]) {
                wolf[nxt_node][!dash] = nxt_dist;
                pq.push({-nxt_dist, nxt_node, !dash});
            }
        }
    }
}


int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    cin >> N >> M;
    adj.assign(N, vector<array<int, 2>>());

    for (int i = 0; i < M; i++) {
        int s, e, w; cin >> s >> e >> w;
        adj[s - 1].push_back({e - 1, w});
        adj[e - 1].push_back({s - 1, w});
    }

    dijkstra1();
    dijkstra2();

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        cnt += fox[i] < min(wolf[i][0], wolf[i][1]);
    }
    
    cout << cnt;
}

