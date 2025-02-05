#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    string s; cin >> s;
    vector<int> dp(N + 1);
    for (int i = 1; i <= N; i++) {
        dp[i] = dp[i - 1] + 1;
        if (i > 1) dp[i] = min(dp[i], dp[i - 2] + 1);
        if (i > 2 && stoi(s.substr(i - 3, 3)) < 642) dp[i] = min(dp[i], dp[i - 3] + 1);
    }
    cout << dp[N];
}