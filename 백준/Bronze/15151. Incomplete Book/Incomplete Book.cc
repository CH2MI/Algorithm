#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    long long k, d; cin >> k >> d;
    long long cnt = 0, day = 0;
    while (1) {
        day += k;
        if (day > d) break;
        k *= 2;
        cnt++;
    }
    cout << cnt;
}
