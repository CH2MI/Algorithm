#include <bits/stdc++.h>
using namespace std;

constexpr int sz = 1 << 20;
long long arr[sz << 1];

void update(int i, long long x) {
    i += sz;
    arr[i] = x;
    while (i > 1) {
        i /= 2;
        arr[i] = arr[i << 1] + arr[i << 1 | 1];
    }
}

long long query(int s, int e, int node = 1, int ns = 0, int ne = sz - 1) {
    if (e < ns || ne < s) return 0;
    if (s <= ns && ne <= e) return arr[node];

    int mid = (ns + ne) / 2;
    return query(s, e, node << 1, ns, mid) + query(s, e, node << 1 | 1, mid + 1, ne);
}


int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int N, M; cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int q, a, b; cin >> q >> a >> b;
        if (!q) {
            if (a > b) swap(a, b);
            cout << query(a - 1, b - 1) << '\n';
        }
        else {
            update(a - 1, b);
        }
    }
}
