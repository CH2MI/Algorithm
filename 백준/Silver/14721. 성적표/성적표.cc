#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<array<long long, 2>> v(N);
    for (auto& [a, b] : v) cin >> a >> b;

    long long ma = 0, mb = 0, m = LLONG_MAX;

    for (long long i = 1; i <= 100; i++) {
        for (long long j = 1; j <= 100; j++) {
            long long sum = 0;
            for (int k = 0; k < N; k++) {
                sum += (long long)pow(v[k][1] - (v[k][0] * i + j), 2);
            }
            if (m > sum) {
                m = sum;
                ma = i; mb = j;
            }
        }
    }
    cout << ma << ' ' << mb;
}