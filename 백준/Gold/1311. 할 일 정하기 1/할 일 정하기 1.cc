#include <iostream>
#include <vector>
#define INF (int)1e9
using namespace std;

int N;
vector<vector<int>> D, dp;

int recursion(int count, int select) {
    if (count == N) return 0;

    if (dp[count][select] != -1) return dp[count][select];

    dp[count][select] = INF;

    for (int i = 0; i < N; i++) {
        if (!(select & (1 << i))) {
            dp[count][select] = min(recursion(count + 1, select | (1 << i)) + D[i][count], dp[count][select]);
        }
    }
    return dp[count][select];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    D.assign(N, vector<int>(N));
    dp.assign(N, vector<int>(1 << N, -1));
    for (auto& i : D) for (auto& j : i) cin >> j;

    cout << recursion(0, 0);
}