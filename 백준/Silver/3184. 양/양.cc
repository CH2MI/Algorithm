#include <bits/stdc++.h>
using namespace std;

int dr[4] = {0, 0, -1, 1};
int dc[4] = {-1, 1, 0, 0};

int R, C;
vector<string> v;
vector<vector<int>> visited;

array<int, 2> DFS(int x, int y) {
    if (x < 0 || x >= R || y < 0 || y >= C || v[x][y] == '#' || visited[x][y]) return {0, 0};
    visited[x][y] = 1;

    int a = 0, b = 0;
    for (int k = 0; k < 4; k++) {
        auto [c, d] = DFS(x + dr[k], y + dc[k]);
        a += c;
        b += d;
    }
    if (v[x][y] == 'o') return {a + 1, b};
    if (v[x][y] == 'v') return {a, b + 1};
    return {a, b};
}


int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> R >> C;
    v.assign(R, string());
    visited.assign(R, vector<int>(C, 0));

    for (int i = 0; i < R; i++) cin >> v[i];

    int a = 0, b = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (v[i][j] != '#' && !visited[i][j]) {
                auto [c, d] = DFS(i, j);
                if (c > d) a += c;
                else b += d;
            }
        }
    }

    cout << a << ' ' << b;
}