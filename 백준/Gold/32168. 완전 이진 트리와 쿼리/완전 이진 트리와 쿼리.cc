#include <bits/stdc++.h>
using namespace std;

long long get_sum(long long N, long long v) {
    if (v > N) return 0;
    auto sum = v;
    auto l = v << 1, r = (v << 1) + 1;
    while (l <= N) {
        r = min(r, N);
        sum += (r - l + 1) * (r + l) / 2;
        l = l << 1;
        r = (r << 1) + 1;
    }
    return sum;
}

int find(long long r, long long v) {
    if (r == v) return 3;
    while (r > 1) {
        if (r >> 1 == v) return r % 2 + 1;
        r >>= 1;
    }
    return 0;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    long long N, M;
    cin >> N >> M;

    auto sum = get_sum(N, 1);
    long long root = 1;
    for (int i = 0; i < M; i++) {
        int q, v; cin >> q >> v;
        if (q == 1) {
            root = v;
        }
        else {
            int result = find(root, v);
            if (!result) cout << get_sum(N, v) << '\n';
            else if (result == 1) {
                cout << sum - get_sum(N, v * 2) << '\n';
            }
            else if (result == 2) {
                cout << sum - get_sum(N, v * 2 + 1) << '\n';
            }
            else {
                cout << sum << '\n';
            }
        }
    }

}