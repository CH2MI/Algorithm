#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        int mx = 0, cur = 0;

        for (int i = 0; i < N; i++) {
            int a, b; cin >> a >> b;
            cur = cur - a + b;
            mx = max(mx, cur);
        }
        cout << mx << '\n';
    }
}