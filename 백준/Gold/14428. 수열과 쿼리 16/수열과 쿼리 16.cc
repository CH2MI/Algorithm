#include <bits/stdc++.h>
using namespace std;

constexpr int sz = 1 << 17;
array<int, 2> arr[sz << 1];

void update(int i, int x) {
    array<int, 2> a = { x, i };
    i += sz;
    arr[i] = a;
    while (i > 1) {
        i /= 2;
        arr[i] = min(arr[i << 1], arr[i << 1 | 1]);
    }
}

array<int, 2> query(int s, int e, int node = 1, int ns = 0, int ne = sz - 1) {
    if (e < ns || ne < s) return {INT_MAX, INT_MAX};
    if (s <= ns && ne <= e) return arr[node];

    int mid = (ns + ne) / 2;
    return min(query(s, e, node << 1, ns, mid), query(s, e, node << 1 | 1, mid + 1, ne));
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        update(i, a);
    }

    int M; cin >> M;
    for (int i = 0; i < M; i++) {
        int q, a, b; cin >> q >> a >> b;
        if (q == 1) update(a - 1, b);
        else cout << query(a - 1, b - 1)[1] + 1 << '\n';
    }
}