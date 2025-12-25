#include <bits/stdc++.h>
using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int N, M;
vector<vector<int>> v;

int simulation(int sr, int sc, int sd) {
    int cnt = 0;

    int cr = sr, cc = sc, cd = sd;
    while (1) {
        if (!v[cr][cc]) {
            ++cnt;
            v[cr][cc] = 2;
        }

        int f = 0;
        for (int k = 0; k < 4; k++) {
            int nr = cr + dx[k];
            int nc = cc + dy[k];
            f |= !v[nr][nc];
        }

        if (!f) {
            int nr = cr - dx[cd];
            int nc = cc - dy[cd];

            if (v[nr][nc] == 1) break;

            cr = nr; cc = nc;
            continue;
        }

        cd = (cd - 1 + 4) % 4;

        if (!v[cr + dx[cd]][cc + dy[cd]]) cr += dx[cd], cc += dy[cd];
    }

    return cnt;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    cin >> N >> M;
    int r, c, d; cin >> r >> c >> d;

    v.assign(N, vector<int>(M));

    for (auto& i : v) for (int& j : i) cin >> j;

    cout << simulation(r, c, d);

}
