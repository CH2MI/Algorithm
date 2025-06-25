#include <bits/stdc++.h>
using namespace std;

long long N;
array<long long, 3> v;

int solve(long long mid) {
    long long cnt = 0;
    for (auto i : v) cnt += mid / i;
    return N <= cnt;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> N;
    for (auto& i : v) cin >> i;

    long long lo = 0, hi = LLONG_MAX;
    while (lo + 1 < hi) {
        long long mid = lo + (hi - lo) / 2;
        if (solve(mid)) hi = mid;
        else lo = mid;
    }

    long long cnt = 0;
    for (auto i : v) cnt += lo / i;
    for (int i = 0; i < 3; i++) {
        if (hi % v[i] == 0) cnt++;
        if (cnt == N) {
            cout << (char)('A' + i) << " win";
            break;
        }
    }
}