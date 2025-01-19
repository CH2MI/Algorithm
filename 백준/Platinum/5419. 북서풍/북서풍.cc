#include <bits/stdc++.h>
using namespace std;

constexpr int sz = 1 << 17;
int arr[sz << 1];

void update(int i) {
    i += sz;
    while (i >= 1) {
        ++arr[i];
        i >>= 1;
    }
}

int query(int s, int e, int node = 1, int ns = 0, int ne = sz - 1) {
    if (e < ns || ne < s) return 0;
    if (s <= ns && ne <= e) return arr[node];

    int mid = (ns + ne) >> 1;
    return query(s, e, node << 1, ns , mid) + query(s, e, node << 1 | 1, mid + 1, ne);
}

void Solve() {
    int n; cin >> n;
    vector<array<int, 2>> v(n);
    vector<int> w(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i][0] >> v[i][1];
        w[i] = v[i][1];
    }

    sort(w.begin(), w.end());
    w.erase(unique(w.begin(), w.end()), w.end());
    for (int i = 0; i < n; i++) {
        int j = lower_bound(w.begin(), w.end(), v[i][1]) - w.begin();
        v[i][1] = j;
    }

    sort(v.begin(), v.end(), [](auto& a, auto& b) {
        if (a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    });

    memset(arr, 0, sizeof(arr));

    long long cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt += (long long)query(v[i][1], sz - 1);
        update(v[i][1]);
    }
    cout << cnt << '\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--) {
        Solve();
    }
}