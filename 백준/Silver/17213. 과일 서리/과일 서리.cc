#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;

int go(int n, int r) {
    if (r == 0) return 1;
    if (n == r) return 1;

    if (dp[n][r] != -1) return dp[n][r];

    return dp[n][r] = go(n - 1, r - 1) + go(n - 1, r);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N, M;
    cin >> N >> M;
    dp.assign(M, vector<int>(M, -1));
    cout << go(M - 1, M - N);
}