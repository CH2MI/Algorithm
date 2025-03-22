#include <bits/stdc++.h>
using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int N, K;
vector<vector<int>> v;
queue<array<int, 3>> q;

void contagion() {
    queue<array<int, 3>> tq;

    for (; !q.empty(); q.pop()) {
        auto [a, i, j] = q.front();
        for (int k = 0; k < 4; k++) {
            int x = i + dx[k], y = j + dy[k];
            if (x < 0 || x >= N || y < 0 || y >= N) continue;
            if (v[x][y]) continue;
            v[x][y] = a;
            tq.push({a, x, y});
        }
    }
    q = tq;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> N >> K;
    v.assign(N, vector<int>(N));

    for (auto& i : v) for (auto& j : i) cin >> j;
    vector<array<int, 3>> a;
    a.reserve(N * N);
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) if (v[i][j]) a.push_back({v[i][j], i, j});
    sort(a.begin(), a.end());
    for (auto i : a) q.push(i);

    int S, X, Y; cin >> S >> X >> Y;
    for (int i = 0; i < S; i++) {
        contagion();
    }
    cout << v[X - 1][Y - 1];
}