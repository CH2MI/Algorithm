#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    long long k; cin >> k;
    long long a, b, c, d;
    cin >> a >> b >> c >> d;

    if (a * k + b == c * k + d) cout << "Yes " <<  a * k + b;
    else cout << "No";
}