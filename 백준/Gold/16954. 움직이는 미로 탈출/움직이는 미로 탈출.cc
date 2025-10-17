#include <bits/stdc++.h>
using namespace std;

constexpr int len = 8;
int dx[9] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
int dy[9] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};

vector<vector<string>> v(len + 1, vector<string>(len));

int BFS() {
    vector<vector<int>> visited(len, vector<int>(len, -1));

    queue<tuple<int, int, int>> q;

    for (int i = 0; i < 9; i++) {
        int nx = len - 1 + dx[i];
        int ny = 0 + dy[i];

        if (nx < 0 || nx >= len || ny < 0 || ny >= len) continue;
        if (nx == 0 && ny == len - 1) return 1;
        if (v[0][nx][ny] == '#') continue;
        if (visited[nx][ny] >= 0) continue;
        visited[nx][ny] = 0;

        if (v[1][nx][ny] == '#') continue;
        q.emplace(nx, ny, 1);
    }

    while (!q.empty()) {
        auto [x, y, cnt] = q.front(); q.pop();

        cnt = min(cnt, 7);
        for (int i = 0; i < 9; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= len || ny < 0 || ny >= len) continue;
            if (nx == 0 && ny == len - 1) return 1;
            if (v[cnt][nx][ny] == '#') continue;
            if (visited[nx][ny] >= cnt) continue;
            visited[nx][ny] = cnt;

            if (v[cnt + 1][nx][ny] == '#') continue;
            q.emplace(nx, ny, cnt + 1);
        }
    }
    return 0;
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    for (auto& s : v[0]) cin >> s;

    for (int i = 1; i < len + 1; i++) {
        v[i][0] = "........";
        for (int j = 1; j < len; j++) {
            v[i][j] = v[i - 1][j - 1];
        }
    }

    cout << BFS();

}