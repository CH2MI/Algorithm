#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int X, Y, Z; cin >> X >> Y >> Z;

    if (X == 3 && Y == 3 && Z == 3) cout << 0;
    else cout << (min({X, Y, Z}) - 1) / 2;
}
