#include <bits/stdc++.h>
using namespace std;

constexpr int sz = 1 << 17;
int arr[sz << 1];

void update(int i, int x) {
    i += sz;
    arr[i] = x;

    i /= 2;
    while (i >= 1) {
        arr[i] = min(arr[i << 1], arr[i << 1 | 1]);
        i /= 2;
    }
}

int query(int s, int e, int node = 1, int ns = 0, int ne = sz - 1) {
    if (e < ns || ne < s) return INT_MAX;
    if (s <= ns && ne <= e) return arr[node];
    int mid = (ns + ne) / 2;
    return min(query(s, e, node << 1, ns, mid), query(s, e, node << 1 | 1, mid + 1, ne));
}


int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N, M; cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int n; cin >> n;
        update(i, n);
    }

    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        cout << query(a - 1, b - 1) << '\n';
    }
}