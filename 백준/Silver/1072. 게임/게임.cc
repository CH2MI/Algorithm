#include <bits/stdc++.h>
using namespace std;

long long X, Y, Z;
int solve(long long mid) {
    long long z = (double)(Y + mid) * 100 / (double)(X + mid);
    return Z != z;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);


    cin >> X >> Y;
    Z = (double)Y * 100 / (double)X;
    if (Z >= 99) {
        cout << -1;
        return 0;
    }

    long long lo = 0, hi = X + 1;
    while (lo + 1 < hi) {
        long long mid = (lo + hi) / 2;
        if (solve(mid)) hi = mid;
        else lo = mid;
    }
    cout << hi;
}