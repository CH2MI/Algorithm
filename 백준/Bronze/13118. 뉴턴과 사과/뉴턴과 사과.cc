#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    array<int, 4> v{};
    for (auto& i : v) cin >> i;

    int x, y, z; cin >> x >> y >> z;

    int i = 0;
    for (; i < 4; i++) {
        if (v[i] == x) break;
    }
    if (i == 4) cout << 0;
    else cout << i + 1;
}