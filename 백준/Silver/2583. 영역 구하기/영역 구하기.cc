#include <bits/stdc++.h>
using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int N, M;
vector<vector<int>> v, visited;;

int BFS(int sx, int sy) {
    queue<array<int, 2>> q;
    q.push({sx, sy});

    int cnt = 0;
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();

        if (x < 0 || x >= N || y < 0 || y >= M) continue;
        if (v[x][y]) continue;
        if (visited[x][y]) continue;

        visited[x][y] = 1;
        ++cnt;

        for (int k = 0; k < 4; k++) q.push({x + dx[k], y + dy[k]});
    }
    return cnt;
}


int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int K; cin >> N >> M >> K;
    v.assign(N, vector<int>(M));
    visited.assign(N, vector<int>(M));

    for (int k = 0; k < K; k++) {
        int x1, x2, y1, y2; cin >> y1 >> x1 >> y2 >> x2;
        for (int i = x1; i < x2; i++) {
            for (int j = y1; j < y2; j++) {
                v[i][j] = 1;
            }
        }
    }

    vector<int> ans;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (visited[i][j] || v[i][j]) continue;
            ans.push_back(BFS(i, j));
        }
    }

    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (int& i : ans) cout << i << ' ';

}