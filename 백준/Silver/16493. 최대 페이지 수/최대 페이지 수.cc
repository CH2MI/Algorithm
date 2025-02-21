#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<vector<int>> dp;
vector<array<int, 2>> v;

int DFS(int n, int m) {
    if (!n || m == M) return 0;
    if (dp[n][m] != -1) return dp[n][m];

    int mx = DFS(n, m + 1);
    for (int i = m; i < M; i++) {
        if (n >= v[i][0]) mx = max(mx, DFS(n - v[i][0], i + 1) + v[i][1]);
    }

    return dp[n][m] = mx;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    v.assign(M, array<int, 2>());
    for (auto& [a, b] : v) cin >> a >> b;
    dp.assign(N + 1, vector<int>(M, -1));

    cout << DFS(N, 0);
}