#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    long long n; cin >> n;

    if (!n) cout << 0;
    else {
        long long sn = sqrt(n);
        if (sn * sn < n) cout << sn + 1;
        else cout << sn;
    }

}