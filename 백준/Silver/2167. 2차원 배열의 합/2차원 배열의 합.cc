#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int N, M; cin >> N >> M;
    vector<vector<int>> v(N, vector<int>(M));

    for (auto& i : v) for (int& j : i) cin >> j;

    vector<vector<int>> ps(N + 1, vector<int>(M + 1));
    for (int i = 1; i <= N; i++) for (int j = 1; j <= M; j++) ps[i][j] = v[i - 1][j - 1] + ps[i - 1][j] + ps[i][j - 1] - ps[i - 1][j - 1];

    int K; cin >> K;
    while (K--) {
        int i, j, x, y; cin >> i >> j >> x >> y;
        cout << ps[x][y] - ps[x][j - 1] - ps[i - 1][y] + ps[i - 1][j - 1] << '\n';
    }
}