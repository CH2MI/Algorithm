#include <bits/stdc++.h>
using namespace std;

constexpr int sz = 1 << 16;
int arr[sz << 1];

void update(int i, int x) {
    i += sz;
    arr[i] = x;
    while (i > 1) {
        i >>= 1;
        arr[i] = arr[i << 1] + arr[i << 1 | 1];
    }
}

int query(int s, int e, int node = 1, int ns = 0, int ne = sz - 1) {
    if (ne < s || e < ns) return 0;
    if (s <= ns && ne <= e) return arr[node];

    int mid = (ns + ne) >> 1;
    return query(s, e, node << 1, ns, mid) + query(s, e, node << 1 | 1, mid + 1, ne);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;

    vector<array<int, 3>> v(N);
    for (auto& [a, b, c] : v) cin >> a >> b >> c;
    sort(v.begin(), v.end(), [](auto& a, auto& b) {
        return a[1] < b[1];
    });

    set<int> set;
    for (int i = 0; i <= v[N - 1][1]; i++) {
        set.insert(i);
    }
    for (auto& [a, b, c] : v) {
        int cnt = c - query(a, b);
        while (cnt > 0) {
            // 2. 할당되지 않은 실험실을 위에서부터 어떻게 할당할 수 있을까요?????????????
            auto itr = --set.upper_bound(b);
            update(*itr, 1);
            set.erase(itr);
            --cnt;
        }
    }
    cout << query(0, sz - 1);
}