#include <bits/stdc++.h>
using namespace std;

int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};

void solve() {
    int R, C; cin >> R >> C;
    string s; cin >> s;
    vector<string> v(R);
    for (int i = 0; i < R; i++) {
        v[i] = s.substr(i * C, C);
    }

    vector<vector<int>> visited(R, vector<int>(C));
    visited[0][0] = 1;
    int d = 0;
    queue<array<int, 3>> q;
    q.push({0, 0, 0});
    string ans;
    s.clear();
    while (!q.empty()) {
        auto [r, c, d] = q.front(); q.pop();

        s += v[r][c];
        if (s.size() == 5) {
            if (s == "00000") ans += ' ';
            else ans += 'A' + stoi(s, 0, 2) - 1;
            s.clear();
        }



        int i;
        for (i = 0; i < 4; i++) {
            int x = r + dr[(d + i) % 4];
            int y = c + dc[(d + i) % 4];
            if (x < 0 || x >= R || y < 0 || y >= C || visited[x][y]) continue;
            break;
        }
        d = (d + i) % 4;
        if (i < 4) q.push({r + dr[d], c + dc[d], d}), visited[r + dr[d]][c + dc[d]] = 1;
    }

    while (!ans.empty() && ans.back() == ' ') ans.pop_back();
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T; cin >> T;
    while (T--) {
        solve();
    }
}