#include <bits/stdc++.h>
using namespace std;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

vector v(5, vector<int>(5));

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    auto visited = v;
    for (auto& i : v) for (auto& j : i) cin >> j;
    int r, c; cin >> r >> c;

    queue<array<int, 3>> q;
    q.push({r, c, 0});
    while (!q.empty()) {
        auto [x, y, cnt] = q.front();
        q.pop();

        if (x < 0 || x >= 5 || y < 0 || y >= 5) continue;
        if (v[x][y] == -1) continue;
        if (visited[x][y]) continue;

        if (v[x][y]) {
            cout << cnt;
            return 0;
        }

        visited[x][y] = 1;
        for (int k = 0; k < 4; k++) {
            q.push({x + dr[k], y + dc[k], cnt + 1});
        }
    }
    cout << -1;
}