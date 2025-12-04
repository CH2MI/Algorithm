#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    long long n, b; cin >> n >> b;

    long long X = 0, Y = 0;

    for (int i = 0; i < n; i++) {
        long long x, y; cin >> x >> y;
        X += x;
        Y -= y;
    }

    Y += n * b;

    long long s = -1;
    if (X < 0) {
        s = -s; X = -X;
    }
    if (Y < 0) {
        s = -s;
        Y = -Y;
    }

    if (!X) cout << "EZPZ";
    else if (Y % X) {

        long long g = gcd(X, Y);
        X /= g; Y /= g;
        cout << s * Y << '/' << X;
    }
    else {
        cout << Y / X * s;
    }



}