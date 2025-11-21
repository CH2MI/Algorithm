#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> matchA, matchB, visited;
vector<vector<int>> adj;
int num = 0;

int dfs(int cur) {
    if (visited[cur] == num) return 0;
    visited[cur] = num;

    for (int nxt : adj[cur]) {
        if (matchB[nxt] == -1 || dfs(matchB[nxt])) {
            matchA[cur] = nxt;
            matchB[nxt] = cur;
            return 1;
        }
    }
    return 0;
}

int match() {
    matchA.assign(n, -1);
    matchB.assign(m, -1);
    visited.assign(n, -1);

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt += dfs(i);
        num++;
    }

    return cnt;
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    cin >> n;
    vector<array<int, 2>> v(n);

    m = 1000001;

    for (int i = 0; i < n; i++) cin >> v[i][0];
    for (int i = 0; i < n; i++) cin >> v[i][1];

    adj.assign(n, vector<int>());

    for (int i = 0; i < n; i++) {
        adj[i].push_back(v[i][0]);
        adj[i].push_back(v[i][1]);
    }

    cout << match();
}