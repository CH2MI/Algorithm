#include <bits/stdc++.h>
using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int N, M;

vector<string> v;

int BFS(array<int, 2> s, array<int, 2> e) {
    vector<vector<int>> visited(N, vector<int>(M));

    queue<array<int, 2>> q;
    q.push({s[0] - 1, s[1] - 1});

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        if (x < 0 || x >= N || y < 0 || y >= M) continue;
        if (visited[x][y]) continue;

        if (v[x][y] == '#') return 1;
        visited[x][y] = 1;

        if (v[x][y] == '1') {
            v[x][y] = '0';
            continue;
        }
        
        for (int k = 0; k < 4; k++)
            q.push({x + dx[k], y + dy[k]});
    }

    return 0;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> N >> M;

    array<int, 2> start{}, end{};

    cin >> start[0] >> start[1] >> end[0] >> end[1];
    v.assign(N, string());

    for (auto& s : v) cin >> s;

    int cnt = 1;

    while (!BFS(start, end)) cnt++;

    cout << cnt;
}