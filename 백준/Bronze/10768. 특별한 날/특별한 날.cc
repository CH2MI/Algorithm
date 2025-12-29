#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    #ifdef LOCAL_DEBUG
        freopen("input.txt", "r", stdin);
    #endif

    int M, D; cin >> M >> D;

    if (M < 2 || (M == 2 && D < 18)) cout << "Before";
    else if (M == 2 && D == 18) cout << "Special";
    else cout << "After";
}
