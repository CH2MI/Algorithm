#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int sz = 1 << 20;
ll arr[sz * 2];

void update(int i, ll x) {
    i += sz;
    arr[i] = x;
    while (i > 1) {
        i /= 2;
        arr[i] = arr[i << 1] + arr[i << 1 | 1];
    }
}

ll sum(int s, int e, int node = 1, int ns = 0, int ne = sz - 1) {
    if (e < ns || ne < s) return 0;
    if (s <= ns && ne <= e) return arr[node];

    int mid = (ns + ne) >> 1;
    return sum(s, e, node << 1, ns, mid) + sum(s, e, node << 1 | 1, mid + 1, ne);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, K; cin >> N >> M >> K;

    for (int i = 0; i < N; i++) {
        ll a; cin >> a;
        update(i, a);
    }
    for (int i = 0; i < M + K; i++) {
        ll a, b, c; cin >> a >> b >> c;
        if (a == 1) update(b - 1, c);
        else cout << sum(b - 1, c - 1) << '\n';
    }
}