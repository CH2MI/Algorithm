#include <bits/stdc++.h>
using namespace std;

constexpr int sz = 1 << 19;
long long arr[sz << 1];

vector<vector<int>> adj;
vector<int> level;
vector<array<int, 2>> ett;
int cnt = 0;

void update(int i) {
    i += sz;
    arr[i] += 1;

    while (i > 1) {
        i /= 2;
        arr[i] = arr[i << 1] + arr[i << 1 | 1];
    }
}

long long query(int s, int e, int node = 1, int ns = 0, int ne = sz - 1) {
    if (e < ns || ne < s) return 0;
    if (s <= ns && ne <= e) return arr[node];

    int mid = (ns + ne) / 2;
    return query(s, e, node << 1, ns, mid) + query(s, e, node << 1 | 1, mid + 1, ne);
}

void go(int pre, int cur) {
    ett[cur][0] = cnt++;

    if (pre != -1) level[cur] = level[pre] + 1;

    for (int nxt : adj[cur]) {
        if (nxt == pre) continue;
        go(cur, nxt);
    }

    ett[cur][1] = cnt++;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int N, C; cin >> N >> C;
    adj.assign(N, vector<int>());
    level.assign(N, 0);
    ett.assign(N, {});

    for (int i = 0; i < N - 1; i++) {
        int s, e; cin >> s >> e;
        adj[s - 1].push_back(e - 1);
        adj[e - 1].push_back(s - 1);
    }

    go(-1, C - 1);

    int M; cin >> M;
    for (int i = 0; i < M; i++) {
        int q, A; cin >> q >> A;
        if (q == 1) {
            update(ett[A - 1][0]);
        }
        else {
            cout << query(ett[A - 1][0], ett[A - 1][1]) * (level[A - 1] + 1) << '\n';
        }
    }
}
