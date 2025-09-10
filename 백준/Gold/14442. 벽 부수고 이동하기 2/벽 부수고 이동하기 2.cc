#include <bits/stdc++.h>
using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int N, M, K;
vector<string> adj;
vector<vector<vector<int>>> visited;

int BFS() {
    visited.assign(N, vector(M, vector(K + 1, 0)));

    queue<array<int, 4>> q;
    q.push({1, K, 0, 0});
    visited[0][0][K] = 1;
    while (!q.empty()) {
        auto [dist, cnt, x, y] = q.front(); q.pop();

        if (x == N - 1 && y == M - 1) return dist;

        for (int k = 0; k < 4; k++) {
            int i = x + dx[k], j = y + dy[k];
            if (i < 0 || i >= N || j < 0 || j >= M) continue;
            if (adj[i][j] == '1') {
                if (cnt) {
                    if (visited[i][j][cnt - 1]) continue;

                    q.push({dist + 1, cnt - 1, i, j});
                    visited[i][j][cnt - 1] = 1;
                }
            }
            else {
                if (visited[i][j][cnt]) continue;

                q.push({dist + 1, cnt, i, j});
                visited[i][j][cnt] = 1;
            }
        }
    }
    return -1;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    cin >> N >> M >> K;
    adj.assign(N, string());
    for (auto& s : adj) cin >> s;

    cout << BFS();
}
