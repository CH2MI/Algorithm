#include <bits/stdc++.h>
using namespace std;

constexpr int sz = 1 << 19;
constexpr int MOD = 1e9 + 7;
typedef long long ll;
ll arr[sz << 1];

void update(int i) {
    i += sz;
    while (i >= 1) {
        ++arr[i];
        i /= 2;
    }
}

ll query(int s, int e, int node = 1, int ns = 0, int ne = sz - 1) {
    if (e < ns || ne < s) return 0;
    if (s <= ns && ne <= e) return arr[node];

    int mid = (ns + ne) / 2;
    return query(s, e, node << 1, ns, mid) + query(s, e, node << 1 | 1, mid + 1, ne);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;

    vector<array<int, 2>> v(N);
    for (auto& [x, y] : v) cin >> x >> y;
    sort(v.begin(), v.end(), [](auto& a, auto& b) {
        return a[1] > b[1];
    });

    long long sum = 0;

    queue<int> q;
    for (int i = 0; i < N; i++) {
        sum = (sum + query(0, v[i][0] + 199999) * query(v[i][0] + 200001, sz - 1) % MOD) % MOD;
        q.push(v[i][0]);
        for (; !q.empty() && i != N - 1 && v[i][1] != v[i + 1][1]; q.pop()) update(q.front() + 200000);
    }

    cout << sum;
}