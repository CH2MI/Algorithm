#include <bits/stdc++.h>

using namespace std;

void Solve() {
    int N; cin >> N;
    vector<long long> v(N);
    for (auto& i : v) cin >> i;
    vector<long long> mx(N);
    mx.back() = v.back();
    for (int i = N - 2; i >= 0; i--) {
        mx[i] = max(v[i], mx[i + 1]);
    }

    long long sum = 0;
    for (int i = 0; i < N; i++) {
        if (v[i] < mx[i]) sum += mx[i] - v[i];
    }
    cout << sum << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T; cin >> T;
    while (T--) {
        Solve();
    }
}