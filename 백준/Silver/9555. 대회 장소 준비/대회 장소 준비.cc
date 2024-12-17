#include <bits/stdc++.h>
using namespace std;

int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        int N, M; cin >> N >> M;

        vector<vector<int>> v(N, vector<int>(M));
        for (auto& i : v) for (int& j : i) cin >> j;
        set<int> set;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (v[i][j] == -1) continue;
                bool f = 0;
                for (int k = 0; k < 8; k++) {
                    int x = i + dx[k], y = j + dy[k];
                    if (x < 0 || x >= N || y < 0 || y >= M) continue;
                    if (v[i][j] == v[x][y]) set.insert(v[i][j]);
                }
            }
        }
        cout << set.size() << '\n';
    }
}