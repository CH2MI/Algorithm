#include <bits/stdc++.h>
using namespace std;
 
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
 
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
 
        int cnt = 0;
        for (int i = 1; i * i <= n + 1; i++) {
            cnt += (n + 1) % i == 0;
        }
 
        if (cnt == 1) cout << 1 << '\n' << 1 << ' ' << n + 1 << '\n';
        else cout << 0 << '\n';
    }
}
