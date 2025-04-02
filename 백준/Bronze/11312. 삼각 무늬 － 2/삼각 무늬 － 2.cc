#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T; cin >> T;
    for (int i = 0; i < T; i++) {
        long long a, b; cin >> a >> b;
        cout << a * a / (b * b) << '\n';
    }
}