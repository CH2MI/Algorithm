#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, k, s;
    cin >> N >> k >> s;
    vector<ll> v(N);
    for (ll& i : v) cin >> i;
    if (k > 36) cout << "MEGA";
    else {
        vector<vector<ll>> dp(N + 1, vector<ll>(k + 1, -1));
        dp[0][k] = s;

        for (int i = 1; i <= N; i++) {
            for (int j = k; j >= 0; j--) {
                if (dp[i - 1][j] > 0) dp[i][j] = min(dp[i - 1][j] + v[i - 1], (ll)1e13);
                if (j < k) {
                    if (dp[i - 1][j + 1] > 0) dp[i][j] = max(dp[i][j], min(dp[i - 1][j + 1] * 2, (ll)1e13));
                }  
            }
        }
        ll mx = -1;
        for (int i = 0; i <= k; i++) {
            mx = max(dp[N][i], mx); 
        }

        if (mx > (ll)1e11) cout << "MEGA";
        else if (mx < 1) cout << -1;
        else cout << mx;
    }
}