#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N; cin >> N;
    vector<array<int, 4>> v((N - 2) / 2);
    int a, b; cin >> a >> b;
    for (auto& [a, b, c, d] : v) cin >> a >> b >> c >> d;
    cin >> a >> b;
    vector<int> hole((N - 2) / 2);
    int K; cin >> K;
    for (int i = 0; i < K; i++) {
        int c, d; cin >> a >> b >> c >> d;
        hole[lower_bound(v.begin(), v.end(), array<int, 4>{a, b, c, d}) - v.begin()] = 1;
    }

    int sum = 0;

    for (int i = 0; i < (N  - 2) / 2; i++) {
        int lmn = v[i][1], rmn = v[i][1];
        int j;
        for (j = i; j >= 0; j--) {
            lmn = min(lmn, v[j][1]);
            if (hole[j]) break;
        }
        if (j == -1) lmn = 0;
        for (j = i; j < (N - 2) / 2; j++) {
            rmn = min(rmn, v[j][1]);
            if (hole[j]) break;
        }
        if (j == (N - 2) / 2) rmn = 0;
        sum += (v[i][2] - v[i][0]) * (v[i][1] - max(rmn, lmn));
    }
    cout << sum;
}