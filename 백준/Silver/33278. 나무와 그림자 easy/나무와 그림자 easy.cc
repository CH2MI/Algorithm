#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N, t; cin >> N >> t;
    vector<array<long long, 2>> v(N);
    for (auto& [x, h] : v) cin >> x >> h;
    sort(v.begin(), v.end());

    long long sum = 0;
    long long height = v[0][1];
    for (int i = 0; i < N - 1; i++) {
        long long a = -t * (v[i + 1][0] - v[i][0]) + height;
        if (a > 0) sum += min(a, v[i + 1][1]);
        height = max(a, v[i + 1][1]);
    }
    cout << sum;
}