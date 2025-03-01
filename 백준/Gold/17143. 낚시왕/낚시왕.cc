#include <bits/stdc++.h>
using namespace std;

int R, C;
vector<vector<array<int, 3>>> v;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, 1, -1};

int fishing(int c) {
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        auto cur = q.front(); q.pop();

        if (cur >= R) continue;
        if (v[cur][c][2] != 0) {
            int ret = v[cur][c][2];
            v[cur][c] = {0, 0, 0};
            return ret;
        }
        q.push(cur + 1);
    }
    return 0;
}

void moving() {
    vector move(R, vector<array<int, 3>>(C));

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (!v[i][j][2]) continue;
            int r = i, c = j;
            int cnt = v[i][j][0];
            for (int k = 0; k < cnt % ((v[i][j][1] < 2 ? R : C) * 2 - 2); k++) {
                r += dr[v[i][j][1]];
                c += dc[v[i][j][1]];
                if (r < 0) r = 1, v[i][j][1] ^= 1;
                if (r == R) r = R - 2, v[i][j][1] ^= 1;
                if (c < 0) c = 1, v[i][j][1] ^= 1;
                if (c == C) c = C - 2, v[i][j][1] ^= 1;
            }
            if (move[r][c][2]) {
                if (move[r][c][2] < v[i][j][2]) move[r][c] = v[i][j];
            }
            else move[r][c] = v[i][j];
        }
    }
    v = move;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int M; cin >> R >> C >> M;

    v.assign(R, vector<array<int, 3>>(C));

    for (int i = 0; i < M; i++) {
        int r, c, s, d, z;
        cin >> r >> c >> s >> d >> z;
        v[r - 1][c - 1] = {s, d - 1, z};
    }
    int sum = 0;
    for (int i = 0; i < C; i++) {
        sum += fishing(i);
        moving();
    }
    cout << sum;
}