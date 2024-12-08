#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, K;
    cin >> N >> M >> K;
    vector<string> v(N);
    for (auto& i : v) cin >> i;
    int n = N / K, m = M / K;

    int sum = 0;
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < K; j++) {
            array<int, 26> arr({0});
            for (int k = 0; k < n; k++) {
                for (int l = 0; l < m; l++) {
                    arr[v[i + k * K][j + l * K] - 'A']++;
                }
            }
            auto itr = max_element(arr.begin(), arr.end());
            sum += n * m - *itr;

            for (int k = 0; k < n; k++) {
                for (int l = 0; l < m; l++) {
                    v[i + k * K][j + l * K] = itr - arr.begin() + 'A';
                }
            }
        }
    }
    cout << sum << '\n';
    for (auto& s : v) {
        for (auto c : s) cout << c;
        cout << '\n';
    }
}
