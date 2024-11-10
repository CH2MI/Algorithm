#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
vector<int> v, indegree, r;
vector<vector<int>> adj;

int topology_sort() {
    queue<int> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (adj[i][j]) indegree[j]++;
        }
    }
    for (int i = 0; i < n; i++) if (!indegree[i]) q.push(i);

    int cnt = 0;
    while (!q.empty()) {
        int k = q.front(); q.pop();

        r[cnt] = k + 1;
        if (++cnt == n) break;

        for (int i = 0; i < n; i++) {
            if (adj[k][i] && !(--indegree[i])) q.push(i);
        } 
    }

    if (cnt < n) return 0;
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        cin >> n;

        v.assign(n, 0);
        indegree.assign(n, 0);
        r.assign(n, 0);
        adj.assign(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            int a; cin >> a;
            v[a - 1] = i;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (v[i] < v[j]) adj[i][j] = 1;
            }
        }

        cin >> m;
        for (int i = 0; i < m; i++) {
            int a, b; cin >> a >> b;
            swap(adj[a - 1][b - 1], adj[b - 1][a - 1]);
        }

        if (topology_sort()) for (int i : r) cout << i << ' ';
        else cout << "IMPOSSIBLE";
        cout << '\n';
    }
}