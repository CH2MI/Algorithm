#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<array<long long, 2>> v(N);
    for (int i = 0; i < N; i++) cin >> v[i][0] >> v[i][1];

    int cnt = 0;
    for (int i = 0; i < N - 2; i++) {
        for (int j = i + 1; j < N - 1; j++) {
            for (int k = j + 1; k < N; k++) {
                long long x1 = v[i][0], y1 = v[i][1], x2 = v[j][0], y2 = v[j][1], x3 = v[k][0], y3 = v[k][1];
                long long d1 = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1),
                d2 = (x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2),
                d3 = (x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1);
                cnt += d1 == d2 + d3 || d2 == d1 + d3 || d3 == d1 + d2;
            }
        }
    }
    cout << cnt;
}
