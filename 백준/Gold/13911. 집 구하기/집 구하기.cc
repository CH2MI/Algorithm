#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
constexpr ll INF = LLONG_MAX;

int V;
vector<vector<pair<int, ll>>> adj;

vector<ll> Dijkstra(vector<int>& v) {
    priority_queue<pair<ll, int>> pq;
    vector<ll> dist(V, INF);

    for (int i = 0; i < V; i++) if (v[i]) pq.emplace(0, i), dist[i] = 0;

    while (!pq.empty()) {
        auto [cur_dist, cur_node] = pq.top(); pq.pop();
        cur_dist = -cur_dist;

        if (dist[cur_node] != cur_dist) continue;

        for (auto& [nxt_node, d] : adj[cur_node]) {
            ll nxt_dist = cur_dist + d;
            if (nxt_dist < dist[nxt_node]) {
                dist[nxt_node] = nxt_dist;
                pq.emplace(-nxt_dist, nxt_node);
            }
        }
    }
    return dist;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int E; cin >> V >> E;
    adj.assign(V, vector<pair<int, ll>>());
    for (int i = 0; i < E; i++) {
        int s, e; ll w;
        cin >> s >> e >> w;
        adj[s - 1].emplace_back(e - 1, w);
        adj[e - 1].emplace_back(s - 1, w);
    }

    int M, x, S, y;
    cin >> M >> x;
    vector<int> m(V);
    for (int i = 0; i < M; i++) {
        int a; cin >> a; m[a - 1] = 1;
    }
    cin >> S >> y;
    vector<int> s(V);
    for (int i = 0; i < S; i++) {
        int a; cin >> a; s[a - 1] = 1;
    }
    vector<ll> md = Dijkstra(m), sd = Dijkstra(s);

    ll mn = INF;
    for (int i = 0; i < V; i++) if (!m[i] && !s[i] && md[i] <= x && sd[i] <= y) mn = min(mn, md[i] + sd[i]);

    if (mn == INF) cout << -1;
    else cout << mn;
}