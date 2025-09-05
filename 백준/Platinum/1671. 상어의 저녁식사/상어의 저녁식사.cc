#include <bits/stdc++.h>
using namespace std;

int N;
vector<vector<int>> adj;
vector<int> A, B, visited;

int DFS(int cur) {
    if (visited[cur]) return 0;
    visited[cur] = 1;

    for (int& nxt : adj[cur]) {
        if (B[nxt] == -1 || DFS(B[nxt])) {
            A[cur] = nxt;
            B[nxt] = cur;
            return 1;
        }
    }
    return 0;
}

int match() {
    A.assign(N << 1, -1);
    B.assign(N, -1);

    for (int i = 0; i < N << 1; i++) {
        visited.assign(N << 1, 0);
        DFS(i);
    }

    int cnt = 0;
    for (int i = 0; i < N; i++) cnt += B[i] == -1;
    return cnt;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    cin >> N;
    vector<array<int, 3>> v(N);

    for (int i = 0; i < N; i++) {
        int a, b, c; cin >> a >> b >> c;
        v[i] = {a, b, c};
    }

    adj.assign(N << 1, {});

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (v[i][0] >= v[j][0] && v[i][1] >= v[j][1] && v[i][2] >= v[j][2])
                adj[i << 1].push_back(j), adj[i << 1 | 1].push_back(j);
            if (v[i][0] <= v[j][0] && v[i][1] <= v[j][1] && v[i][2] <= v[j][2])
                if (v[i][0] != v[j][0] || v[i][1] != v[j][1] || v[i][2] != v[j][2])
                adj[j << 1].push_back(i), adj[j << 1 | 1].push_back(i);
        }
    }

    cout << match();

}