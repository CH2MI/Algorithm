#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T; cin >> T;
    while (T--) {
        int E, N; cin >> E >> N;
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            int a; cin >> a;
            cnt += a > E;
        }
        cout << cnt << '\n';
    }
}
