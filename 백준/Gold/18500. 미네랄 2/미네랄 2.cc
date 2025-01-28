#include <bits/stdc++.h>
using namespace std;

int R, C;
vector<string> adj;

int dR[4] = {-1, 0, 1, 0};
int dC[4] = {0, 1, 0, -1};

void Throw(int r, bool isLeft) {
    queue<int> q;
    q.push(isLeft ? 0 : C - 1);
    int dir = isLeft ? 1 : -1;

    while (!q.empty()) {
        auto c = q.front(); q.pop();

        if (c < 0 || c >= C) continue;
        if (adj[r][c] == 'x') {
            adj[r][c] = '.';
            return;
        }

        q.push(c + dir);
    }
}

void Fall() {
    vector visited(R, vector<int>(C));

    queue<array<int, 2>> q;
    for (int i = 0; i < C; i++) q.push({R - 1, i});
    while (!q.empty()) {
        auto [r, c] = q.front(); q.pop();

        if (r < 0 || r >= R || c < 0 || c >= C) continue;
        if (adj[r][c] == '.') continue;
        if (visited[r][c]) continue;

        visited[r][c] = 1;

        for (int k = 0; k < 4; k++) q.push({r + dR[k], c + dC[k]});
    }

    int h = R;
    q = queue<array<int, 2>>();
    for (int r = R - 1; r >= 0; r--) {
        for (int c = 0; c < C; c++) {
            if (adj[r][c] == 'x' && !visited[r][c]) {
                for (int k = 1; r + k <= R; k++) {
                    if (r + k == R) {
                        h = min(h, k - 1);
                        break;
                    }
                    if (adj[r + k][c] == 'x') {
                        if (visited[r + k][c]) h = min(h, k - 1);
                        break;
                    }
                }
                q.push({r, c});
            }
        }
    }

    for (; !q.empty(); q.pop()) {
        auto [r, c] = q.front();
        adj[r][c] = '.';
        adj[r + h][c] = 'x';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> R >> C;
    adj.assign(R, string());
    for (auto& s : adj) cin >> s;

    int T; cin >> T;
    bool isLeft = 1;
    while (T--) {
        int r; cin >> r;
        Throw(R - r, isLeft);
        Fall();
        isLeft ^= 1;
    }
    for (auto& s : adj) cout << s << '\n';
}