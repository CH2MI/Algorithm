#include <bits/stdc++.h>
using namespace std;
constexpr int sz = 1 << 17;
int arr1[sz * 2], arr2[sz * 2];

void update(int i, int x) {
    i += sz;
    arr1[i] = x; arr2[i] = x;
    while (i > 1) {
        i /= 2;
        arr1[i] = max(arr1[i << 1], arr1[i << 1 | 1]);
        arr2[i] = min(arr2[i << 1], arr2[i << 1 | 1]);
    }
}

int query1(int s, int e, int node = 1, int ns = 0, int ne = sz - 1) {
    if (e < ns || ne < s) return 0;
    if (s <= ns && ne <= e) return arr1[node];

    int mid = (ns + ne) >> 1;
    return max(query1(s, e, node << 1, ns, mid), query1(s, e, node << 1 | 1, mid + 1, ne));
}

int query2(int s, int e, int node = 1, int ns = 0, int ne = sz - 1) {
    if (e < ns || ne < s) return INT_MAX;
    if (s <= ns && ne <= e) return arr2[node];

    int mid = (ns + ne) >> 1;
    return min(query2(s, e, node << 1, ns, mid), query2(s, e, node << 1 | 1, mid + 1, ne));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;

    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        update(i, a);
    }
    for (int i = 0; i < M; i++) {
        int s, e; cin >> s >> e;
        cout << query2(s - 1, e - 1) << ' ' << query1(s - 1, e - 1) << '\n';
    }
}