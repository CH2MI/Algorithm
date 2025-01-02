#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, X; cin >> N >> X;
    vector<int> sum(N + 1);
    for (int i = 1; i <= N; i++) {
        int n; cin >> n;
        sum[i] = sum[i - 1] + n;
    }
    int mx = 0, cnt = 1;
    for (int i = X; i <= N; i++) {
        int value = sum[i] - sum[i - X];
        if (mx < value) mx = value, cnt = 1;
        else if (mx == value) cnt++;
    }
    if (!mx) cout << "SAD";
    else cout << mx << '\n' << cnt;
}
