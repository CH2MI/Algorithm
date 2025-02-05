#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> v;
vector<vector<int>> dp;

int DFS(int n, int s) {
    if (n > N) return 0;

    if (dp[n][s] != -1) return dp[n][s];
    dp[n][s] = INT_MAX;

    if (v[n]) dp[n][s] = DFS(n + 1, s);
    else {
        dp[n][s] = min({DFS(n + 1, s) + 10000, DFS(n + 3, s + 1) + 25000, DFS(n + 5, s + 2) + 37000});
        if (s >= 3) dp[n][s] = min(dp[n][s], DFS(n + 1, s - 3));
    }
    return dp[n][s];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int M; cin >> N >> M;
   v.assign(N + 1, 0);
    for (int i = 0; i < M; i++) {
        int a; cin >> a;
        v[a] = 1;
    }

    dp.assign(N + 1, vector<int>(N + 1, -1));
    cout << DFS(1, 0);
}