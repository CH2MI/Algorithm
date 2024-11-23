#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll getnxt(ll A, ll D) {
    ll nxt = 0;
    while (A > 0) {
        ll t = A % 10;
        nxt += pow(t, D);
        A /= 10;
    }
    return nxt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll A, D; cin >> A >> D;
    set<ll> s;
    while (s.find(A) == s.end()) {
        s.insert(A);
        A = getnxt(A, D);
    }
    while (s.find(A) != s.end()) {
        s.erase(A);
        A = getnxt(A, D);
    }
    cout << s.size();

}