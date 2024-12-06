#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (1) {
        int a, b; cin >> a >> b;
        if (!a && !b) break;
        cout << a / b << ' ' << a % b << " / " << b << '\n';
    }
}
