#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int N, Q; cin >> N >> Q;
    long long mn = LLONG_MAX;
    int idx;
    for (int i = 0; i < N; i++) {
        long long p, k, c; cin >> p >> k >> c;
        long long cnt = (Q - 1) / k;
        long long sum = p + cnt * (cnt + 1) / 2 * c;
        if (sum < mn) {
            idx = i + 1;
            mn = sum;
        }
    }

    cout << idx << ' ' << mn;
}
