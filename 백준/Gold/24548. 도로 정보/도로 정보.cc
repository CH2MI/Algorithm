#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N; cin >> N;
    string s; cin >> s;
    vector<array<int, 4>> ps(N + 1);
    int dp[3][3][3][3] = {};

    dp[0][0][0][0] = 1;
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        ps[i + 1] = ps[i];
        if (s[i] == 'T') ps[i + 1][0] = (ps[i + 1][0] + 1) % 3;
        else if (s[i] == 'G') ps[i + 1][1] = (ps[i + 1][1] + 1) % 3;
        else if (s[i] == 'F') ps[i + 1][2] = (ps[i + 1][2] + 1) % 3;
        else if (s[i] == 'P') ps[i + 1][3] = (ps[i + 1][3] + 1) % 3;

        cnt += dp[ps[i + 1][0]][ps[i + 1][1]][ps[i + 1][2]][ps[i + 1][3]];
        dp[ps[i + 1][0]][ps[i + 1][1]][ps[i + 1][2]][ps[i + 1][3]]++;
    }
    cout << cnt;
}