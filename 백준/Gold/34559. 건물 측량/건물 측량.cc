#include <bits/stdc++.h>
using namespace std;
 
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
 
int N, M;
vector<string> v;
vector<vector<int>> visited;
 
 
void BFS() {
    queue<array<int, 2>> q;
    q.push({0, 0});
 
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
 
        if (x < 0 || x >= N || y < 0 || y >= M) continue;
        if (v[x][y] == '1') continue;
        if (visited[x][y]) continue;
 
        visited[x][y] = 1;
 
        for (int i = 0; i < 4; i++)
            q.push({x + dx[i], y + dy[i]});
    }
}
 
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
 
    cin >> N >> M;
    v.assign(N, string());
    for (auto& s : v) cin >> s;
 
    visited.assign(N, vector<int>(M));
    BFS();
 
    vector<vector<int>> ps(N + 1, vector<int>(M + 1));
 
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            ps[i][j] = ps[i - 1][j] + ps[i][j - 1] - ps[i - 1][j - 1] + !visited[i - 1][j - 1];
        }
    }
 
    int Q; cin >> Q;
    for (int i = 0; i < Q; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
 
        int ans = ps[x2][y2] - ps[x1 - 1][y2] - ps[x2][y1 - 1] + ps[x1 - 1][y1 - 1];
        if (!ans) cout << "Yes\n";
        else cout << "No " << ans << '\n';
    }
 
 
}
