#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<vector<int>> adj;
vector<int> a, b, visited;

int DFS(int cur) {
    if (visited[cur]) return 0;

    visited[cur] = 1;

    for (int nxt : adj[cur]) {
        if (b[nxt] == -1 || DFS(b[nxt])) {
            a[cur] = nxt;
            b[nxt] = cur;
            return 1;
        }
    }
    return 0;
}

int Match() {
    a.assign(N << 1, -1);
    b.assign(M, -1);
    int cnt = 0;

    for (int i = 0; i < N << 1; i++) {
        visited.assign(N << 1, 0);
        cnt += DFS(i);
    }

    return cnt;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    cin >> N >> M;

    adj.assign(N << 1, {});
    for (int i = 0; i < N; i++) {
        int K; cin >> K;
        for (int j = 0; j < K; j++) {
            int a; cin >> a;
            adj[i << 1].push_back(a - 1);
            adj[i << 1 | 1].push_back(a - 1);
        }
    }

    cout << Match();
}