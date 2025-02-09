#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> v;
vector<vector<array<int, 3>>> dp;

array<int, 3> DFS(int l, int r, int turn) {
    if (l == r) return {v[l], v[l] * turn , v[l] * !turn};

    if (dp[l][r][0] != INT_MAX) return dp[l][r];
    dp[l][r][0] = INT_MIN;

    auto a = DFS(l + 1, r, !turn), b = DFS(l, r - 1, !turn);

    if (v[l] - a[0] < v[r] - b[0]) {
        return dp[l][r] = {v[r] - b[0], b[1] + v[r] * turn, b[2] + v[r] * turn};
    }

    return dp[l][r] = {v[l] - a[0], a[1] + v[l] * turn, a[2] + v[l] * turn};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        cin >> N;
        v.assign(N, 0);
        dp.assign(N, vector<array<int, 3>>(N, {INT_MAX, 0, 0}));
        for (int& i : v) cin >> i;
        cout << DFS(0, N - 1, 1)[1] << '\n';
    }
}

