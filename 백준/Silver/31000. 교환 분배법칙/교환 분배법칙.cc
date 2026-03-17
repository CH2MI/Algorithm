#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int N; cin >> N;

    int cnt = 0;

    for (int i = -N; i <= N; i++) {
        if (i == 0) cnt += (2 * N + 1) * (2 * N + 1);
        else {
            int k = 1 - i;
            int mn = max(-N, k - N);
            int mx = min(N, k + N);
            cnt += max(mx - mn + 1, 0);
        }
    }

    cout << cnt;
}
