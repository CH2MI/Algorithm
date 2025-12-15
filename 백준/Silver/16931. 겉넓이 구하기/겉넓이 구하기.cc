#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int N, M; cin >> N >> M;
    vector<vector<int>> v(N, vector<int>(M));

    for (auto& i : v) {
        for (int& j : i) cin >> j;
    }

    int sum1 = N * M, sum2 = 0, sum3 = 0;
    for (int i = 0; i < N; i++) {
        int pre = 0;
        for (int j = 0; j < M; j++) {
            if (pre < v[i][j]) sum2 += v[i][j] - pre;
            pre = v[i][j];
        }
    }

    for (int i = 0; i < M; i++) {
        int pre = 0;
        for (int j = 0; j < N; j++) {
            if (pre < v[j][i]) sum3 += v[j][i] - pre;
            pre = v[j][i];
        }
    }

    cout << (sum1 + sum2 + sum3) * 2;
}
