#include <bits/stdc++.h>
using namespace std;

int A(int v) {
    if (v < 1 || v > 21) return 0;
    if (v == 1) return 5'000'000;
    if (v <= 3) return 3'000'000;
    if (v <= 6) return 2'000'000;
    if (v <= 10) return 500'000;
    if (v <= 15) return 300'000;
    return 100'000;
}

int B(int v) {
    if (v < 1 || v > 31) return 0;
    if (v == 1) return 5'120'000;
    if (v <= 3) return 2'560'000;
    if (v <= 7) return 1'280'000;
    if (v <= 15) return 640'000;
    return 320'000;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    #ifdef LOCAL_DEBUG
        freopen("input.txt", "r", stdin);
    #endif

    int T; cin >> T;
    while (T--) {
        int a, b; cin >> a >> b;
        cout << A(a) + B(b) << '\n';
    }
}
