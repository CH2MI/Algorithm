#include <bits/stdc++.h>
using namespace std;

int solve(long long y, long long c, long long r, long long mid) {
    long long premid = mid;
    for (int i = 0; i < y; i++) {
        if (mid < c) return 0;
        mid -= c;
        mid = mid * (1.0 + (r / 100.0));
        if (premid < mid) return 1;
        premid = mid;
    }
    return 1;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    while (1) {
        long long y, c, r;
        cin >> y >> c >> r;
        if (!y && !c && !r) break;

        long long lo = 0, hi = y * c;
        while (lo + 1 < hi) {
            long long mid = (lo + hi) / 2;
            if (solve(y, c, r, mid)) hi = mid;
            else lo = mid;
        }
        cout << hi << '\n';
    }
}