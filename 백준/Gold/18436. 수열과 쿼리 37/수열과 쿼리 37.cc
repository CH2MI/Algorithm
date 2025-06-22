#include <bits/stdc++.h>
using namespace std;

constexpr int sz = 1 << 17;
int arr[sz << 1];

void update(int i, int a) {
    i += sz;
    arr[i] = a % 2;
    while (i > 1) {
        i /= 2;
        arr[i] = arr[i << 1] + arr[i << 1 | 1];
    }
}

int query(int s, int e, int node = 1, int ns = 0, int ne = sz - 1) {
    if (e < ns || ne < s) return 0;
    if (s <= ns && ne <= e) return arr[node];

    int mid = (ns + ne) / 2;
    return query(s, e, node << 1, ns, mid) + query(s, e, node << 1 | 1, mid + 1, ne);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        update(i + 1, a);
    }

    int M; cin >> M;

    for (int i = 0; i < M; i++) {
        int q, l, r;
        cin >> q >> l >> r;
        if (q == 1) update(l, r);
        else if (q == 2) cout << (r - l + 1) - query(l, r) << '\n';
        else cout << query(l, r) << '\n';
    }

}