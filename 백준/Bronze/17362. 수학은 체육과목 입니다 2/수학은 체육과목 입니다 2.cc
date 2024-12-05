#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    n = (n - 1) % 8;
    int ans = 1;
    switch (n) {
        case 1: case 7:
            ans = 2;
        break;
        case 2: case 6:
            ans = 3;
        break;
        case 3: case 5:
            ans = 4;
        break;
        case 4:
            ans = 5;
        break;
    }
    cout << ans;
}