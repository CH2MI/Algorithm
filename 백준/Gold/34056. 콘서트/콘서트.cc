#include <bits/stdc++.h>
using namespace std;

int N;
vector<long long> v;

void go(int s, long long x, int d) {
    for (int i = s; i >= 0 && i < N && x; i += d) {
        long long a = min(x, v[i]);
        x -= a;
        v[i] += a;
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> N;
    v.assign(N, 0);
    for (auto& i : v) cin >> i;

    int Q; cin >> Q;
    for (int i = 0; i < Q; i++) {
        int q; cin >> q;

        if (q == 1) {
            int c, x; cin >> c >> x;
            go(c - 1, x, -1);
            go(c, x, 1);
        }
        else {
            int c; cin >> c;
            cout << v[c - 1] << '\n';
        }
    }
}