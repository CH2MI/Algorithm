#include <bits/stdc++.h>
using namespace std;

constexpr int sz = 1 << 18;
int arr[sz << 1];

vector<int> v;
vector<array<int, 2>> euler;
vector<vector<int>> adj;

void eulertour(int cur, int& cnt) {
    euler[cur][0] = cnt++;

    for (int& nxt : adj[cur]) eulertour(nxt, cnt);

    euler[cur][1] = cnt++;
}

void update(int i, int k) {
    i += sz;
    while (i >= 1) {
        arr[i] += k;
        i >>= 1;
    }
}

int query(int s, int e, int node = 1, int ns = 0, int ne = sz - 1) {
    if (e < ns || ne < s) return 0;
    if (s <= ns && ne <= e) return arr[node];

    int mid = (ns + ne) >> 1;
    return query(s, e, node << 1, ns, mid) + query(s, e, node << 1 | 1, mid + 1, ne);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    v.assign(n, 0);
    adj.assign(n, vector<int>());
    euler.assign(n, array<int, 2>());
    for (int i = 0; i < n; i++) {
        int s; cin >> s;
        if (s == -1) continue;
        adj[s - 1].push_back(i);
    }
    int cnt = 0;
    eulertour(0, cnt);

    for (int i = 0; i < m; i++) {
        int q, s, w; cin >> q;
        if (q == 1) {
            cin >> s >> w;
            update(euler[s - 1][0], w);
        }
        else {
            cin >> s;
            cout << query(euler[s - 1][0], euler[s - 1][1]) << '\n';
        }
    }
}