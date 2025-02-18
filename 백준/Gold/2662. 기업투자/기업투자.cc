#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<vector<int>> v, dp, bt;

int DFS(int n, int cur) {
    if (cur == M) return 0;
    if (dp[n][cur] != -1) return dp[n][cur];
    int mx = 0;

    for (int i = 0; i <= n; i++) {
        int ans = DFS(n - i, cur + 1) + v[i][cur];
        if (mx < ans) {
            mx = ans;
            bt[n][cur] = i;
        }
    }

    return dp[n][cur] = mx;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    v.assign(N + 1, vector<int>(M));
    for (int i = 1; i <= N; i++) {
        int a; cin >> a;
        for (int j = 0; j < M; j++) cin >> v[i][j];
    }
    bt.assign(N + 1, vector<int>(M));
    dp.assign(N + 1, vector<int>(M, -1));
    cout << DFS(N, 0) << '\n';
    int n = N;
    for (int i = 0; i < M; i++) {
        cout << bt[n][i] << ' ';
        n -= bt[n][i];
    }
}