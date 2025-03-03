#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N; cin >> N;
    vector<vector<int>> v(N, vector<int>(N)), sum1(N + 1, vector<int>(N + 1)), sum2(sum1);
    for (auto& i : v) for (int& j : i) cin >> j;
    int K; cin >> K;
    vector<int> d(K), sum3(K + 1);
    for (int& i : d) cin >> i;
    sort(d.begin(), d.end(), greater<>());

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            sum1[i][j] = v[i - 1][j - 1] + sum1[i - 1][j] + sum1[i][j - 1] - sum1[i - 1][j - 1];
            sum2[i][j] = (v[i - 1][j - 1] == 0) + sum2[i - 1][j] + sum2[i][j - 1] - sum2[i - 1][j - 1];
        }
    }
    for (int i = 1; i <= K; i++) {
        sum3[i] = d[i - 1] + sum3[i - 1];
    }

    int mx = 0;
    for (int k = 1; k <= N; k++) {
        for (int i = 0; i < N - k + 1; i++) {
            for (int j = 0; j < N - k + 1; j++) {
                int cnt = sum2[i + k][j + k] - sum2[i][j + k] - sum2[i + k][j] + sum2[i][j];
                if (cnt > K) continue;

                int sum = sum1[i + k][j + k] - sum1[i][j + k] - sum1[i + k][j] + sum1[i][j];
                sum += sum3[cnt];
                mx = max(mx, sum);
            }
        }
    }

    cout << mx;
}