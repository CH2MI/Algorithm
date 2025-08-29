#include <bits/stdc++.h>
using namespace std;

constexpr int sz = 1 << 17;
vector<int> arr[sz << 1];

void merge(int node, int a, int b) {
    int i = 0, l = 0, k = 0;
    int m = (int)arr[a].size(), n = (int)arr[b].size();
    arr[node] = vector<int>(m + n);

    while (l < m && k < n) {
        if (arr[a][l] < arr[b][k]) {
            arr[node][i++] = arr[a][l++];
        }
        else {
            arr[node][i++] = arr[b][k++];
        }
    }

    while (l < m) arr[node][i++] = arr[a][l++];
    while (k < n) arr[node][i++] = arr[b][k++];
}

void init(int node = 1, int ns = 0, int ne = sz - 1) {
    if (ne == ns) return;

    int mid = (ns + ne) / 2;
    init(node << 1, ns, mid);
    init(node << 1 | 1, mid + 1, ne);
    merge(node, node << 1, node << 1 | 1);
}

int query(int s, int e, int q, int node = 1, int ns = 0, int ne = sz - 1) {
    if (ne < s || e < ns) return 0;
    if (s <= ns && ne <= e) {
        return (int)arr[node].size()  - (upper_bound(arr[node].begin(), arr[node].end(), q) - arr[node].begin());
    }

    int mid = (ns + ne) / 2;
    return query(s, e, q, node << 1, ns, mid) + query(s, e, q, node << 1 | 1, mid + 1, ne);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        arr[i + sz] = {a};
    }

    init();

    int M; cin >> M;
    for (int i = 0; i < M; i++) {
        int a, b, c; cin >> a >> b >> c;
        cout << query(a - 1, b - 1, c) << '\n';
    }


}