#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
constexpr ll INF = LLONG_MAX;

int V, E;
vector<vector<array<ll, 2>>> adj;

ll Dijkstra(int s, int e) {
    vector<ll> dist(V, INF);
    dist[s] = 0;
    priority_queue<array<ll, 2>> pq;
    pq.push({0, s});


    while (!pq.empty()) {
        auto [cur_dist, cur_node] = pq.top();
        pq.pop();
        cur_dist = -cur_dist;

        if (cur_dist != dist[cur_node]) continue;

        for (const auto& [nxt_node, nxt_dist] : adj[cur_node]) {
            if (cur_dist + nxt_dist < dist[nxt_node]) {
                dist[nxt_node] = cur_dist + nxt_dist;
                pq.push({-(cur_dist + nxt_dist), nxt_node});
            }
        }
    }

    return dist[e];
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> V >> E;
    adj.assign(V, vector<array<ll, 2>>());

    for (int i = 0; i < E; i++) {
        ll s, e, w; cin >> s >> e >> w;
        adj[s - 1].push_back({e - 1, w});
        adj[e - 1].push_back({s - 1, w});
    }

    vector<int> v(10);
    vector<ll> d(10, 0);
    for (int& i : v) cin >> i;
    int cur = 0;
    for (int i = 1; i < 10; i++) {
        ll dist = Dijkstra(v[cur] - 1, v[i] - 1);
        if (dist == INF) {
            d[i] = -1;
        }
        else {
            d[i] = d[cur] + dist;
            cur = i;
        }
    }

    int me; cin >> me;
    vector<int> ans;
    for (int i = 0; i < 10; i++) {
        if (d[i] == -1) continue;
        if (Dijkstra(me - 1, v[i] - 1) <= d[i]) ans.push_back(v[i]);
    }
    sort(ans.begin(), ans.end());

    if (ans.empty()) cout << -1;
    else cout << ans.front();
}