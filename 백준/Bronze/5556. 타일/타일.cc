#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K; cin >> N >> K;
    for (int i = 0; i < K; i++) {
        int a, b; cin >> a >> b;
        int ans = min({a - 1, b - 1, N - a, N - b});
        cout << ans % 3 + 1 << '\n';
    }
}