#include <bits/stdc++.h>
using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int N, M;
vector<bool> tmp;
vector<array<int, 2>> virus;
vector<vector<int>> v;

int BFS() {
    vector adj(v);
    queue<array<int, 3>> q;

    for (int i = 0; i < virus.size(); i++) {
        if (tmp[i]) {
            q.push({1, virus[i][0], virus[i][1]});
            adj[virus[i][0]][virus[i][1]] = 0;
        }
    }

    while (!q.empty()) {
        auto [cnt, x, y] = q.front(); q.pop();

        if (cnt < -1) cnt = -cnt;

        if (x < 0 || x >= N || y < 0 || y >= N) continue;
        if (adj[x][y] > 0 || adj[x][y] < -1) continue;

        if (!adj[x][y]) adj[x][y] = cnt;
        else adj[x][y] = -cnt;

        for (int k = 0; k < 4; k++) {
            q.push({cnt + 1, x + dx[k], y + dy[k]});
        }
    }

    int mx = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!adj[i][j]) return INT_MAX;
            mx = max(mx, adj[i][j]);
        }
    }
    return mx - 1;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> N >> M;
    v.assign(N, vector<int>(N));
    virus.reserve(M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> v[i][j];
            if (v[i][j] == 2) {
                virus.push_back({i, j});
                v[i][j] = -1;
            }
        }
    }

    int mn = INT_MAX;
    tmp.assign(virus.size(), false);
    fill(tmp.end() - M, tmp.end(), true);
    do {
        mn = min(mn, BFS());
    } while (next_permutation(tmp.begin(), tmp.end()));


    if (mn == INT_MAX) cout << -1;
    else cout << mn;
}