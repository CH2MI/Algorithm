#include <bits/stdc++.h>
using namespace std;

constexpr int offset = 1500;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int N, M; cin >> N >> M;
    vector<string> S(N);
    vector<vector<int>> v(N + 2 * offset , vector<int>(M + 2 * offset));

    queue<array<int, 3>> q;

    for (auto& s : S) cin >> s;
    int K; cin >> K;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (S[i][j] == 'o') q.push({K, i + offset, j + offset});
        }
    }

    int cnt = 0;

    while (!q.empty()) {
        auto [k, x, y] = q.front();
        q.pop();

        if (k == -1) continue;
        if (v[x][y]) continue;

        v[x][y] = 1;
        cnt++;
        for (int l = 0; l < 4; l++) {
            int i = x + dx[l], j = y + dy[l];
            q.push({k - 1, i, j});
        }
    }
    cout << cnt;
}