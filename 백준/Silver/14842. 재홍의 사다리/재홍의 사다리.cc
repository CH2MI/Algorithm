#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int W, H, N; cin >> W >> H >> N;

    cout << fixed << setprecision(6);

    double ans = 0;

    if (N % 2) ans = (double)(N - 1) * (N - 1) / (4 * N);
    else ans = (double)(N - 2) / 4;

    cout << ans * 2 * H;
}
