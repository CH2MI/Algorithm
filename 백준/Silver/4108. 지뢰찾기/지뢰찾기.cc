#include <bits/stdc++.h>
using namespace std;

int dr[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dc[8] = {-1, -1, -1, 0, 0, 1, 1, 1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (1) {
        int R, C; cin >> R >> C;
        if (!R && !C) break;

        vector<string> v(R, string());
        for (auto& i : v) cin >> i;

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (v[i][j] == '*') continue;
                int cnt = 0;
                for (int k = 0; k < 8; k++) {
                    int r = i + dr[k];
                    int c = j + dc[k];
                    if (r < 0 || r >= R || c < 0 || c >= C) continue;
                    if (v[r][c] == '*') cnt++;
                }
                v[i][j] = cnt + '0';
            }
        }

        for (auto& i : v) cout << i << '\n';
    }

}