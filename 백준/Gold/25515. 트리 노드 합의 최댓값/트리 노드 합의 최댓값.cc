#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> v;
vector<vector<int>> adj;

long long dfs(int pre, int cur) {
    long long sum = 0;

    for (int& nxt : adj[cur]) {
        if (nxt == pre) continue;

        long long ans = dfs(cur, nxt);
        if (ans > 0) sum += ans;
    }

    return sum + v[cur];
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> N;
    v.assign(N, 0);
    adj.assign(N, vector<int>());

    for (int i = 0; i < N - 1; i++) {
        int s, e; cin >> s >> e;
        adj[s].push_back(e);
        adj[e].push_back(s);
    }

    for (int i = 0; i < N; i++) cin >> v[i];

    cout << dfs(-1, 0);

}