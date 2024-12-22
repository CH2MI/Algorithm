#include <bits/stdc++.h>
using namespace std;

constexpr int sz = 1 << 17;
int arr1[sz * 2], arr2[sz * 2];

void update(int i, int x) {
    i += sz;
    arr1[i] = arr2[i] = x;
    while (i > 1) {
        i >>= 1;
        arr1[i] = min(arr1[i << 1], arr1[i << 1 | 1]);
        arr2[i] = max(arr2[i << 1], arr2[i << 1 | 1]);
    }
}

int query1(int s, int e, int node = 1, int ns = 0, int ne = sz - 1) {
    if (ne < s || e < ns) return (int)1e9;
    if (s <= ns && ne <= e) return arr1[node];

    int mid = (ns + ne) >> 1;
    return min(query1(s, e, node << 1, ns, mid), query1(s, e, node << 1 | 1, mid + 1, ne));
}

int query2(int s, int e, int node = 1, int ns = 0, int ne = sz - 1) {
    if (ne < s || e < ns) return -1;
    if (s <= ns && ne <= e) return arr2[node];

    int mid = (ns + ne) >> 1;
    return max(query2(s, e, node << 1, ns, mid), query2(s, e, node << 1 | 1, mid + 1, ne));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        int N, K; cin >> N >> K;
        for (int i = 0; i < N; i++) update(i, i);
        for (int i = 0; i < K; i++) {
            int Q, A, B; cin >> Q >> A >> B;
            if (!Q) {
                int s = arr1[A + sz], e = arr1[B + sz];
                update(A, e); update(B, s);
            }
            if (Q) {
                if (A == query1(A, B) && B == query2(A, B)) cout << "YES\n";
                else cout << "NO\n";
            }
        }
    }
}