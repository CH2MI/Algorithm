#include <bits/stdc++.h>
using namespace std;

vector<int> pi, dp;

int GetPi(int S, int N) {
    pi.assign(N - S, 0);
    vector<int> s(dp.begin() + S, dp.end());
    int i = 1, j = 0;

    for (; i < N - S; i++) {
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            pi[i] = ++j;
    }
    return S - pi.back();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int M, N; cin >> M >> N;
    vector<int> v(N);
    for (int& i : v) cin >> i;

    int len = 1 << 20;

    dp.assign(len, 0);

    for (int i = 1; i <= len; i++) {
        vector<int> t(23);
        for (int j : v) {
            if (i - j < 0) continue;
            t[dp[i - j]] = 1;
        }
        for (int j = 0; j <= 22; j++) {
            if (!t[j]) {
                dp[i] = j;
                break;
            }
        }
    }

    if (M >= len / 2) {
        int cycle = GetPi(len / 2, len);
        int l = M - (len / 2);
        int cnt = count(dp.begin() + len / 2, dp.begin() + len / 2 + cycle, 0) * (l / cycle);
        cnt += count(dp.begin() + len / 2, dp.begin() + len / 2 + (l % cycle) + 1, 0) + count(dp.begin() + 1, dp.begin() + len / 2, 0);
        cout << cnt;
    }
    else cout << count(dp.begin() + 1, dp.begin() + M + 1, 0);
}