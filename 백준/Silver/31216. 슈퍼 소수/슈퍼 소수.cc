#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> prime;

    int N = 318137;
    vector<bool> check(N + 1, 0);
    for (int i = 2; i <= N; i++) {
        if (check[i]) continue;
        prime.push_back(i);

        for (int j = i + i; j <= N; j += i) {
            check[j] = true;
        }
    }
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        cout << prime[prime[n - 1] - 1] << '\n';
    }
}