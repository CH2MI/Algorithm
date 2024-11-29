#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, R;
vector<vector<int>> adj;


long long BFS() {
    vector<int> level(N, -1), count(N);
    queue<pair<int, int>> q;
    q.push({R - 1, 0});
    int cnt = 1;
    while (!q.empty()) {
        auto [cur, l] = q.front();
        q.pop();

        if (level[cur] != -1) continue;
        level[cur] = l;
        count[cur] = cnt++;

        for (int nxt : adj[cur]) {
            q.push({nxt, l + 1});
        }
    }
    long long sum = 0;
    for (int i = 0; i < N; i++) {
        sum += (long long)level[i] * (long long)count[i];
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int M;
    cin >> N >> M >> R;
    adj.assign(N, vector<int>());

    for (int i = 0; i < M; i++) {
        int s, e;
        cin >> s >> e;
        adj[s - 1].push_back(e - 1);
        adj[e - 1].push_back(s - 1);
    }

    cout << BFS();
}