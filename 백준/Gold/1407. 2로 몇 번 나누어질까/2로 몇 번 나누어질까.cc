#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll count(ll a) {
    ll cnt = a;
    ll b = 2;
    while (b <= a) {
        ll c = a / b;
        cnt += c * (b >> 1);
        b <<= 1;
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll A, B; cin >> A >> B;
    cout << count(B) - count(A - 1);
}