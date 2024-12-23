#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
constexpr int sz = 1 << 17;
ll arr[sz << 1];

void update(int s, int e, int k, int node = 1, int ns = 0, int ne = sz - 1) {
    if (ne < s || e < ns) return;
    if (s <= ns && ne <= e) {
        arr[node] += k;
        return;
    }
    int mid = (ns + ne) >> 1;
    update(s, e, k, node << 1, ns, mid); update(s, e, k, node << 1 | 1, mid + 1, ne);
}

ll query(int i) {
    i += sz;
    ll sum = 0;
    while (i >= 1) {
        sum += arr[i];
        i >>= 1;
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N;
    for (int i = sz; i < sz + N; i++) {
        cin >> arr[i];
    }
    cin >> M;
    for (int i = 0; i < M; i++) {
        int q; cin >> q;
        if (q == 1) {
            int s, e, k; cin >> s >> e >> k;
            update(s - 1, e - 1, k);
        }
        else {
            int k; cin >> k;
            cout << query(k - 1) << '\n';
        }
    }

}