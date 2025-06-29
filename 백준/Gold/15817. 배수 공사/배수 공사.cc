#include <bits/stdc++.h>
using namespace std;

int N, X;
vector<array<int, 2>> v;
vector<vector<int>> dp;

int DFS(int x, int a) {
    if (x == X) return 1;
    if (x > X) return 0;
    if (a == N) return 0;

    if (dp[x][a] != -1) return dp[x][a];

    int ret = 0;
    for (int i = 0; i <= v[a][1]; i++) {
        ret += DFS(x + v[a][0] * i, a + 1);
    }
    return dp[x][a] = ret;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> N >> X;
    v.assign(N, array<int, 2>());
    dp.assign(X + 1, vector<int>(N, -1));

    for (auto& [l, c] : v) cin >> l >> c;

    cout << DFS(0, 0);
}