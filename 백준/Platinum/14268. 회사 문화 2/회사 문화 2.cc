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

void update(int s, int e, int k, int node = 1, int ns = 0, int ne = sz - 1) {
    if (ne < s || e < ns) return;
    if (s <= ns && ne <= e) {
        arr[node] += k;
        return;
    }

    int mid = (ns + ne) >> 1;
    update(s, e, k, node << 1, ns, mid); update(s, e, k, node << 1 | 1, mid + 1, ne);
}

int query(int k) {
    int i = k + sz;
    int sum = 0;
    while (i >= 1) {
        sum += arr[i];
        i >>= 1;
    }
    return sum;
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
        int n, s, w; cin >> n;
        if (n == 1) {
            cin >> s >> w;
            update(euler[s - 1][0], euler[s - 1][1], w);
        }
        else {
            cin >> s;
            cout << query(euler[s - 1][0]) << '\n';
        }
    }

}