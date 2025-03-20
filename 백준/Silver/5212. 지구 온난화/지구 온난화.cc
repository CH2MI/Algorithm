#include <bits/stdc++.h>
using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int R, C; cin >> R >> C;

    vector<string> v(R);
    for (auto& s : v) cin >> s;
    vector<string> ans(v);

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (v[i][j] != 'X') continue;
            int cnt = 0;
            for (int k = 0; k < 4; k++) {
                int x = i + dx[k], y = j + dy[k];
                if (x < 0 || x >= R || y < 0 || y >= C) {
                    cnt++;
                    continue;
                }
                cnt += v[x][y] != 'X';
            }
            if (cnt >= 3) ans[i][j] = '.';
        }
    }

    int minX = R, maxX = 0, minY = C, maxY = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (ans[i][j] != '.' && ans[i][j] != 'X') ans[i][j] = '.';
            if (ans[i][j] == 'X') {
                minX = min(minX, i);
                maxX = max(maxX, i);
                minY = min(minY, j);
                maxY = max(maxY, j);
            }
        }
    }



    for (int i = minX; i <= maxX; i++) {
        for (int j = minY; j <= maxY; j++) cout << ans[i][j];
        cout << '\n';
    }
}