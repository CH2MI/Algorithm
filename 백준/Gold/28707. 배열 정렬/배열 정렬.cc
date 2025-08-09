#include <bits/stdc++.h>
using namespace std;

int N;
vector<array<int, 3>> edges;

int Dijkstra(string s) {
    unordered_map<string, int> m;
    priority_queue<pair<int, string>> pq;
    pq.push({0, s});
    m[s] = 0;

    while (!pq.empty()) {
        auto [cur_dist, cur_node] = pq.top(); pq.pop();
        cur_dist = -cur_dist;

        for (auto [s, e, w] : edges) {
            string nxt_node = cur_node;
            swap(nxt_node[s], nxt_node[e]);

            int nxt_dist = cur_dist + w;
            auto itr = m.find(nxt_node);

            if (itr == m.end() || nxt_dist < itr->second) {
                m[nxt_node] = nxt_dist;
                pq.push({-nxt_dist, nxt_node});
            }
        }
    }

    sort(s.begin(), s.end());
    auto itr = m.find(s);
    if (itr == m.end()) return -1;
    return itr->second;
}


int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> N;
    vector<int> v(N);
    for (int& i : v) cin >> i;

    int M; cin >> M;
    for (int i = 0; i < M; i++) {
        int s, e, w; cin >> s >> e >> w;
        edges.push_back({s - 1, e - 1, w});
    }

    string s;
    for (int i : v) {
        s += (char)(i - 1 + '0');
    }

    cout << Dijkstra(s);
}