#include <bits/stdc++.h>
using namespace std;

int L, R, C;
vector<vector<string>> adj;

int dl[6] = {0, 0, 0, 0, -1, 1};
int dr[6] = {1, 0, -1, 0, 0, 0};
int dc[6] = {0, 1, 0, -1, 0, 0};

int BFS(array<int, 3> s) {
    vector visited(L, vector(R, vector(C, 0)));
    queue<array<int, 4>> q;
    q.push({s[0], s[1], s[2], 0});

    while (!q.empty()) {
        auto [x, y, z, cnt] = q.front(); q.pop();
        
        if (x < 0 || x >= L || y < 0 || y >= R || z < 0 || z >= C) continue;
        if (adj[x][y][z] == '#') continue;
        if (visited[x][y][z]) continue;
        if (adj[x][y][z] == 'E') return cnt;

        visited[x][y][z] = 1;

        for (int k = 0; k < 6; k++) {
            int l = x + dl[k];
            int r = y + dr[k];
            int c = z + dc[k];
            q.push({l, r, c, cnt + 1});
        }
    }
    return -1;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (1) {
        cin >> L >> R >> C;
        if (!L && !R && !C) break;
        adj.assign(L, vector<string>(R, string()));
        array<int, 3> s;
        for (int i = 0; i < L; i++) {
            for (int j = 0; j < R; j++) {
                cin >> adj[i][j];
                for (int k = 0; k < C; k++) {
                    if (adj[i][j][k] == 'S') s = {i, j, k};
                }
            }
        }

        int ans = BFS(s);
        if (ans == -1) cout << "Trapped!\n";
        else cout << "Escaped in " << ans << " minute(s).\n";
    }

}