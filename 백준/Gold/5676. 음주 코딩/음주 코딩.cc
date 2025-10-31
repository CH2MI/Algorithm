#include <bits/stdc++.h>
using namespace std;

constexpr int sz = 1 << 17;
int arr[sz << 1];

void update(int i, int x) {
    i += sz;
    arr[i] = x;

    while (i > 1) {
        i /= 2;
        arr[i] = arr[i << 1] * arr[i << 1 | 1];
    }
}

int query(int s, int e, int node = 1, int ns = 0, int ne = sz - 1) {
    if (ne < s || e < ns) return 1;
    if (s <= ns && ne <= e) return arr[node];

    int mid = (ns + ne) / 2;
    return query(s, e, node << 1, ns, mid) * query(s, e, node << 1 | 1, mid + 1, ne);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int N, K;
    while (cin >> N >> K) {
        memset(arr, 0, sizeof(arr));

        for (int i = 0; i < N; i++) {
            int a; cin >> a;
            if (a > 0) update(i, 1);
            else if (a < 0) update(i, -1);
            else update(i , 0);
        }

        for (int i = 0; i < K; i++) {
            char c; int a, b;
            cin >> c >> a >> b;
            if (c == 'C') {
                if (b > 0) update(a - 1, 1);
                else if (b < 0) update(a - 1, -1);
                else update(a - 1, 0);
            }
            else {
                int ans = query(a - 1, b - 1);
                if (ans > 0) cout << '+';
                else if (ans < 0) cout << '-';
                else cout << 0;
            }
        }
        cout << '\n';
    }
}