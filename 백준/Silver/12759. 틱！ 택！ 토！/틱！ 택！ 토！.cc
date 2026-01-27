#include <bits/stdc++.h>
using namespace std;

int judge(vector<vector<int>>& v) {
    for (int i = 0; i < 3; i++) {
        if (v[i][0] == v[i][1] && v[i][1] == v[i][2] && v[i][0]) return v[i][0];
        if (v[0][i] == v[1][i] && v[1][i] == v[2][i] && v[0][i]) return v[0][i];
    }

    if (v[0][0] == v[1][1] && v[1][1] == v[2][2] && v[0][0]) return v[0][0];
    if (v[2][0] == v[1][1] && v[1][1] == v[0][2] && v[2][0]) return v[2][0];

    for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) if (!v[i][j]) return -1;
    return 0;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int N; cin >> N; vector<vector<int>> v(3, vector<int>(3, 0));
    int a, b;
    while (cin >> a >> b) {
        v[a - 1][b - 1] = N;
        if (N == 2) --N;
        else ++N;

        int ans = judge(v);
        if (ans == -1) continue;

        cout << ans;
        break;
    }

}
