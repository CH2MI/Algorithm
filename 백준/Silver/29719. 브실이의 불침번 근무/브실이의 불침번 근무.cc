#include <bits/stdc++.h>

using namespace std;

constexpr long long MOD = 1000000007;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    long long N, M; cin >> N >> M;

    long long mx = 1;
    for (int i = 0; i < N; i++) mx = mx * M % MOD;

    long long ans = 1;
    for (int i = 0; i < N; i++) ans = ans * (M - 1) % MOD;

    cout << (mx - ans + MOD) % MOD;
}