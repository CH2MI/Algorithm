#include <iostream>
#include <cstring>
#include <climits>
using namespace std;

int dp[101][101][101][101];

int recursion(int turn, int a, int b, int c) {
    if (dp[turn][a][b][c] != -1) return dp[turn][a][b][c];
    if (!a && !b && !c) return 0;

    int ret = INT_MIN, t;
    t = min(turn, a);
    if (t) ret = max(ret, t - recursion(turn + 1, a - t, b, c));
    t = min(turn, b);
    if (t) ret = max(ret, t - recursion(turn + 1, a, b - t, c));
    t = min(turn, c);
    if (t) ret = max(ret, t - recursion(turn + 1, a, b, c - t));

    return dp[turn][a][b][c] = ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int a, b, c;
    cin >> a >> b >> c;
    memset(dp, -1, sizeof(dp));

    int ret = recursion(1, a, b, c);
    if (ret > 0) cout << 'F';
    else if (ret < 0) cout << 'S';
    else cout << 'D';
}