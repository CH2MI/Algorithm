#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<array<int, 2>>> adj;

void Topology_sort(int s, int e) {
    vector<int> indegree(n);
    vector<pair<int, vector<int>>> arr(n);
    queue<int> q;
    for (int i = 0; i < n; i++) {
        for (auto& [e, w] : adj[i]) indegree[e]++;
    }
    q.push(s);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (auto& [nxt, w] : adj[cur]) {
            if (!--indegree[nxt]) q.push(nxt);
            if (arr[cur].first + w > arr[nxt].first) {
                arr[nxt].first = arr[cur].first + w;
                arr[nxt].second = {cur};
            }
            else if (arr[cur].first + w == arr[nxt].first) {
                arr[nxt].second.push_back(cur);
            }
        }
    }

    cout << arr[e].first << '\n';
    int cnt = 0;
    vector<int> visited(n);
    q.push(e);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        if (visited[cur]) continue;
        visited[cur] = 1;
        for (int& nxt : arr[cur].second) {
            q.push(nxt);
            cnt++;
        }
    }
    cout << cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int m;
    cin >> n >> m;

    adj.assign(n, vector<array<int, 2>>());

    while(m--) {
        int s, e, w;
        cin >> s >> e >> w;
        adj[s - 1].push_back({e - 1, w});
    }

    int s, e; cin >> s >> e;
    Topology_sort(s - 1, e - 1);
}