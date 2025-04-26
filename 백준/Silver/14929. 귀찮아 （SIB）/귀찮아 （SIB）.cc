#include <bits/stdc++.h>
using namespace std;


int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N; cin >> N;
    vector<long long> v(N);
    for (auto& i : v) cin >> i;

    vector<long long> ps(N + 1);
    for (int i = 1; i <= N; i++) ps[i] = v[i - 1] + ps[i - 1];

    long long sum = 0;
    for (int i = 0; i < N; i++) {
        sum += v[i] * (ps.back() - ps[i + 1]);
    }
    cout << sum;
}
