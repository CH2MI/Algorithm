#include <bits/stdc++.h>
using namespace std;

int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int N, M; cin >> N >> M;

    vector<vector<int>> v(N, vector<int>(M)), visited(v);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> v[i][j];
        }
    }

    int cnt = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!v[i][j] || visited[i][j]) continue;

            queue<array<int, 2>> q; q.push({i, j});
            while (!q.empty()) {
                auto [x, y] = q.front(); q.pop();

                if (x < 0 || x >= N || y < 0 || y >= M) continue;
                if (!v[x][y] || visited[x][y]) continue;

                visited[x][y] = 1;

                for (int k = 0; k < 8; k++) q.push({x + dx[k], y + dy[k]});
            }

            ++cnt;
        }
    }

    cout << cnt;

}
