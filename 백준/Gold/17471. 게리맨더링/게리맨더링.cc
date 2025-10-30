#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> v, sector, visited;
vector<vector<int>> adj;

void DFS(int cur, int s) {
    visited[cur] = 1;

    for (int& nxt : adj[cur]) {
        if (sector[nxt] != s) continue;
        if (visited[nxt]) continue;
        DFS(nxt, s);
    }
}

int isPossible() {
    visited.assign(N, 0);

    int s0 = -1, s1 = -1;
    for (int i = 0; i < N; i++) {
        if (!sector[i]) {
            s0 = i;
            break;
        }
    }
    for (int i = 0; i < N; i++) {
        if (sector[i]) {
            s1 = i;
            break;
        }
    }

    if (s0 == -1 || s1 == -1) return 0;

    DFS(s0, 0); DFS(s1, 1);

    return count(visited.begin(), visited.end(), 0) == 0;
}

int go(int cur) {
    if (cur == N) {
        if (isPossible()) {
            array<int, 2> arr{};
            for (int i = 0; i < N; i++) {
                arr[sector[i]] += v[i];
            }
            return abs(arr[0] - arr[1]);
        }
        return INT_MAX;
    }

    int ans = INT_MAX;

    ans = min(ans, go(cur + 1));

    sector[cur] = 1;
    ans = min(ans, go(cur + 1));

    sector[cur] = 0;

    return ans;
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    cin >> N;
    v.assign(N, 0);
    sector.assign(N, 0);
    adj.assign(N, vector<int>());

    for (int& i : v) cin >> i;
    for (auto& a : adj) {
        int n; cin >> n;
        a.assign(n, 0);
        for (int& i : a) cin >> i, --i;
    }

    int ans = go(0);
    if (ans == INT_MAX) cout << -1;
    else cout << ans;
}