#include <bits/stdc++.h>
using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int N, M;;
vector<vector<int>> s, d, visited;

void BFS(int sx, int sy, int a, int b) {
    queue<array<int, 2>> q;
    q.push({sx, sy});
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        if (x < 0 || x >= N || y < 0 || y >= M) continue;
        if (s[x][y] != a) continue;
        if (visited[x][y]) continue;

        visited[x][y] = 1;
        s[x][y] = b;

        for (int i = 0; i < 4; i++) q.push({x + dx[i], y + dy[i]});
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> N >> M;

    s.assign(N, vector<int>(M));
    d.assign(N, vector<int>(M));
    visited.assign(N, vector<int>(M));

    for (auto& i : s) for (int& j : i) cin >> j;
    for (auto& i : d) for (int& j : i) cin >> j;

    int b = 0;

    for (int i = 0; i < N && !b; i++) {
        for (int j = 0; j < M && !b; j++) {
            if (s[i][j] != d[i][j]) {
                BFS(i, j, s[i][j], d[i][j]);
                b = 1;
            }
        }
    }

    b = 1;
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) if (s[i][j] != d[i][j]) b = 0;

    cout << (b ? "YES" : "NO");
}