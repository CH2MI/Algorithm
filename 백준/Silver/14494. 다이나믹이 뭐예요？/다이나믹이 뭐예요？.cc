#include <iostream>
#define MOD 1000000007
using namespace std;

int dp[1001][1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = ((dp[i][j - 1] + dp[i - 1][j]) % MOD + dp[i - 1][j - 1]) % MOD; 
        }
    }
    cout << dp[n][m];
}