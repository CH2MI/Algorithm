#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<string> v;
vector<vector<int>> visited;

pair<int, int> getdelta(char c) {
    if (c == 'U') return {-1, 0};
    if (c == 'R') return {0, 1};
    if (c == 'D') return {1, 0};
    return {0, -1};
}

bool DFS(int x, int y) {
    if (visited[x][y] == 1) return true;
    if (visited[x][y] == -1) return false;

    auto [dx, dy] = getdelta(v[x][y]);
    int i = x + dx, j = y + dy;
    visited[x][y] = 1;
    bool f = DFS(i, j);
    visited[x][y] = -1;
    return f;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    v.assign(N, string());
    visited.assign(N, vector<int>(M));
    for (auto& i : v) cin >> i;

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!visited[i][j]) cnt += DFS(i, j);
        }
    }
    cout << cnt;
}