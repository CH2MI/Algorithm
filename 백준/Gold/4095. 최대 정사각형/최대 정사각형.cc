#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int arr[1001][1001], dp[1001][1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    while (1) {
        int N, M; cin >> N >> M;
        if (!N && !M) break;

        memset(arr, 0, sizeof(arr));
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < N; i++) 
            for (int j = 0; j < M; j++) 
                cin >> arr[i][j];
        
        int mx = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (!arr[i][j]) dp[i][j] = 0;
                else if (!i || !j || !arr[i][j - 1] || !arr[i - 1][j] || !arr[i - 1][j - 1]) dp[i][j] = 1;
                else dp[i][j] = min({dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]}) + 1;
                mx = max(mx, dp[i][j]);
            }
        }

        cout << mx << '\n';
    }
}