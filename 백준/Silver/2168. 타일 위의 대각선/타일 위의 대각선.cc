#include <bits/stdc++.h>
using namespace std;


int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int x, y; cin >> x >> y;
    cout << x + y - gcd(x, y);
}