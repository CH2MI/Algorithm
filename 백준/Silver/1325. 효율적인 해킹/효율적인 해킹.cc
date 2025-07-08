#include <bits/stdc++.h>
using namespace std;

int N;
vector<vector<int>> adj;

int BFS(int s) {
    int cnt = 0;
    vector<int> visited(N);
    queue<int> q;
    q.push(s);
    visited[s] = 1;
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (int& nxt : adj[cur]) {
            if (visited[nxt]) continue;
            visited[nxt] = 1;
            cnt++;
            q.push(nxt);
        }
    }

    return cnt;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int M; cin >> N >> M;
    adj.assign(N, vector<int>());

    for (int i = 0; i < M; i++) {
        int s, e; cin >> e >> s;
        adj[s - 1].push_back(e - 1);
    }

    vector<int> ans(N);
    for (int i = 0; i < N; i++) {
        ans[i] = BFS(i);
    }

    int mx = *max_element(ans.begin(), ans.end());
    for (int i = 0; i < N; i++) {
        if (ans[i] == mx) cout << i + 1 << ' ';
    }
}