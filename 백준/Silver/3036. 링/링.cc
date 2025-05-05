#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N; cin >> N;
    vector<int> v(N);
    for (int& i : v) cin >> i;

    int l = 1, r = 1;
    for (int i = 0; i < N - 1; i++) {
        int a = v[i], b = v[i + 1];
        int c = gcd(a, b);
        a /= c, b /= c;
        l *= a, r *= b;
        c = gcd(l, r);
        l /= c, r /= c;
        cout << l << '/' << r << '\n';
    }
}