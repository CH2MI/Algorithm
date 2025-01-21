#include <bits/stdc++.h>
using namespace std;

char arr[4] = {'Z', 'O', 'A', 'C'};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;
    vector v(N, vector<char>(M));
    for (auto& i : v) for (auto& j : i) cin >> j;

    vector dp(N + 1, vector<array<int, 4>>(M + 1)), rdp(dp);

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            for (int k = 0; k < 4; k++) {
                dp[i][j][k] = max(dp[i - 1][j][k], dp[i][j - 1][k]) + (v[i - 1][j - 1] == arr[k]);
            }
        }
    }

    for (int i = N - 1; i >= 0; i--) {
        for (int j = M - 1; j >= 0; j--) {
            for (int k = 0; k < 4; k++) {
                rdp[i][j][k] = max(rdp[i + 1][j][k], rdp[i][j + 1][k]) + (v[i][j] == arr[k]);
            }
        }
    }

    array<int, 4> ans{};
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            for (int k = 0; k < 4; k++) {
                if (v[i - 1][j - 1] != arr[k]) continue;
                ans[k] = max({ans[k], dp[i][j][k] + rdp[i][0][k], dp[i][j][k] + rdp[0][j][k]});
            }
        }
    }
    for (int& i : ans) cout << i << ' ';
}