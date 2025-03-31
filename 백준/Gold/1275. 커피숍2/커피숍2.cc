#include <bits/stdc++.h>
using namespace std;

constexpr int sz = 1 << 18;
long long arr[sz << 1];

void update(int i, long long x) {
    i += sz;
    arr[i] = x;
    while (i > 1) {
        i /= 2;
        arr[i] = arr[i << 1] + arr[i << 1 | 1];
    }
}

long long query(int s, int e, int node = 1, int ns = 1, int ne = sz) {
    if (e < ns || ne < s) return 0;
    if (s <= ns && ne <= e) return arr[node];
    int mid = (ns + ne) / 2;
    return query(s, e, node << 1, ns, mid) + query(s, e, node << 1 | 1, mid + 1, ne);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N, Q; cin >> N >> Q;
    for (int i = 0; i < N; i++) {
        int n; cin >> n;
        update(i, n);
    }
    for (int i = 0; i < Q; i++) {
        int x, y, a, b; cin >> x >> y >> a >> b;
        if (x < y) cout << query(x, y) << '\n';
        else cout << query(y, x) << '\n';
        update(a - 1, b);
    }
}