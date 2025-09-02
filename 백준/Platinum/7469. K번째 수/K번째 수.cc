#include <bits/stdc++.h>
using namespace std;

constexpr int sz = 1 << 17;
vector<int> arr[sz << 1];

void merge(int node) {
    int left = node << 1, right = node << 1 | 1;
    int L = (int)arr[left].size(), R = (int)arr[right].size();
    int l = 0, r = 0, i = 0;

    arr[node] = vector<int>(L + R);

    while (l < L && r < R) {
        if (arr[left][l] < arr[right][r]) arr[node][i++] = arr[left][l++];
        else arr[node][i++] = arr[right][r++];
    }

    while (l < L) arr[node][i++] = arr[left][l++];
    while (r < R) arr[node][i++] = arr[right][r++];
}

void init (int node = 1, int ns = 0, int ne = sz - 1) {
    if (ns == ne) return;

    int mid = (ns + ne) / 2;
    init(node << 1, ns, mid);
    init(node << 1 | 1,  mid + 1, ne);
    merge(node);
}

int query(int s, int e, int q, int node = 1, int ns = 0, int ne = sz - 1) {
    if (e < ns || ne < s) return 0;
    if (s <= ns && ne <= e) {
        return upper_bound(arr[node].begin(), arr[node].end(), q) - arr[node].begin();
    }

    int mid = (ns + ne) / 2;
    return query(s, e, q, node << 1, ns, mid) + query(s, e, q, node << 1 | 1, mid + 1, ne);
}


int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int n, Q; cin >> n >> Q;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        arr[i + sz] = {a};
    }

    init();

    for (int i = 0; i < Q; i++) {
        int a, b, c; cin >> a >> b >> c;

        int lo = -1000000001, hi = 1000000000;
        while (lo + 1 < hi) {
            int mid = (lo + hi) / 2;
            if (query(a - 1, b - 1, mid) >= c) hi = mid;
            else lo = mid;
        }

        cout << hi << '\n';
    }

}
