#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    vector<vector<int>> v(100, vector<int>(100));

    int N, M; cin >> N >> M;

    for (int i = 0; i < N; i++) {
        int sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;

        for (int j = sx - 1; j < ex; j++) {
            for (int k = sy - 1; k < ey; k++) {
                v[j][k] += 1;
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            cnt += (v[i][j] > M);
        }
    }
    cout << cnt;
}