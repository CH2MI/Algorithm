#include <bits/stdc++.h>
using namespace std;

constexpr int sz = 1 << 18;
int arr[sz << 1], lazy[sz << 1];
vector<array<int, 2>> euler;
vector<vector<int>> adj;

void eulertour(int cur, int& cnt) {
    euler[cur][0] = cnt++;

    for (int& nxt : adj[cur]) eulertour(nxt, cnt);

    euler[cur][1] = cnt++;
}

void propagate(int node, int ns, int ne) {
    if (lazy[node] == -1) return;
    if (node < sz) {
        lazy[node << 1] = lazy[node];
        lazy[node << 1 | 1] = lazy[node];
    }

    arr[node] = lazy[node] * (ne - ns + 1);
    lazy[node] = -1;
}

void update(int s, int e, int k, int node = 1, int ns = 0, int ne = sz - 1) {
    propagate(node, ns, ne);

    if (e < ns || ne < s) return;
    if (s <= ns && ne <= e) {
        lazy[node] = k;
        propagate(node, ns, ne);
        return;
    }

    int mid = (ns + ne) >> 1;
    update(s, e, k, node << 1, ns, mid); update(s, e, k, node << 1 | 1, mid + 1, ne);
    arr[node] = arr[node << 1] + arr[node << 1 | 1];
}

int query(int s, int e, int node = 1, int ns = 0, int ne = sz - 1) {
    propagate(node, ns, ne);

    if (e < ns || ne < s) return 0;
    if (s <= ns && ne <= e) return arr[node];

    int mid = (ns + ne) >> 1;
    return query(s, e, node << 1, ns, mid) + query(s, e, node << 1 | 1, mid + 1, ne);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(lazy, -1, sizeof(lazy));
    int N; cin >> N;
    euler.assign(N, array<int, 2>());
    adj.assign(N, vector<int>());
    for (int i = 0; i < N; i++) {
        int n; cin >> n;
        if (!n) continue;
        adj[n - 1].push_back(i);
    }

    int cnt = 0;
    eulertour(0, cnt);
    update(euler[0][0], euler[0][1], 1);

    int M; cin >> M;
    while (M--) {
        int q, i; cin >> q >> i;
        if (q == 1) update(euler[i - 1][0] + 1, euler[i - 1][1] - 1, 1);
        else if (q == 2) update(euler[i - 1][0] + 1, euler[i - 1][1] - 1, 0);
        else cout << query(euler[i - 1][0] + 1, euler[i - 1][1] - 1) / 2 << '\n';
    }
}