#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<vector<int>> adj;
vector<int> matchA, matchB, visited;

int DFS(int cur) {
    if (visited[cur]) return false;
    visited[cur] = 1;

    for (int nxt = 0; nxt < M; nxt++) {
        if (!adj[cur][nxt])continue;
        if (matchB[nxt] == -1 || DFS(matchB[nxt])) {
            matchA[cur] = nxt;
            matchB[nxt] = cur;
            return true;
        }
    }

    return false;
}

int Match() {
    matchA.assign(N, -1);
    matchB.assign(M, -1);

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        visited.assign(N, 0);
        cnt += DFS(i);
    }

    return cnt;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    cin >> N >> M;
    adj.assign(N, vector<int>(M));

    for (int i = 0; i < N; i++) {
        int K; cin >> K;
        for (int j = 0; j < K; j++) {
            int a; cin >> a;
            adj[i][a - 1] = 1;
        }
    }

    cout << Match();
}