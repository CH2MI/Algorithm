#include <bits/stdc++.h>
using namespace std;

constexpr int sz = 1 << 20;
long long arr[sz << 1];

void update(int i, int x) {
    i += sz;
    arr[i] += x;
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

    int N, Q; cin >> N >> Q;
    for (int i = 0; i < Q; i++) {
        int a; cin >> a;
        if (a == 1) {
            int p, x; cin >> p >> x;
            update(p - 1, x);
        }
        else {
            int p, q; cin >> p >> q;
            cout << query(p - 1, q - 1) << '\n';
        }
    }
}
