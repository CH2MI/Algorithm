#include <iostream>
#include <vector>
#include <cmath>
#define INF (int)1e9
using namespace std;

int N;
vector<int> v;
vector<vector<vector<int>>> dp;

int cost(int a, int b) {
    if (a == b) return 1;
    if (!a) return 2;
    if (abs(a - b) == 2) return 4;
    return 3;
}

int DP(int cnt, int l, int r) {
    if (cnt == N) return 0;

    if (dp[cnt][l][r] != INF) return dp[cnt][l][r];

    int mn = INF;

    if (v[cnt] != r) mn = min(DP(cnt + 1, v[cnt], r) + cost(l, v[cnt]), mn);
    if (v[cnt] != l) mn = min(DP(cnt + 1, l, v[cnt]) + cost(r, v[cnt]), mn);

    return dp[cnt][l][r] = mn;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);


    while (true) {
        int a; cin >> a;
        if (!a) break;
        v.push_back(a);
    }

    N = (int)v.size();
    dp.assign(N, vector<vector<int>>(5, vector<int>(5, INF)));
    cout << DP(0, 0, 0);
}