#include <bits/stdc++.h>
using namespace std;

int N;

vector<int> visited;
vector<vector<int>> capacity, flow;

int dfs(int cur, int f, int sink) {
    if (cur == sink) return 1;

    visited[cur] = 1;

    for (int nxt = 0; nxt < N; nxt++) {
        int r = capacity[cur][nxt] - flow[cur][nxt];
        if (r > 0 && !visited[nxt]) {
            int amount = dfs(nxt, min(f, r), sink);
            if (amount > 0) {
                flow[cur][nxt] += amount;
                flow[nxt][cur] -= amount;
                return amount;
            }

        }
    }

    return 0;
}

int Maximun_Flow(int source, int sink) {
    int total_flow = 0;

    while (1) {
        visited.assign(N, 0);
        int amount = dfs(source, INT_MAX, sink);
        if (!amount) break;
        total_flow += amount;
    }
    return total_flow;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int P; cin >> N >> P;
    capacity.assign(N, vector<int>(N));
    flow.assign(N, vector<int>(N));

    for (int i = 0; i < P; i++) {
        int s, e; cin >> s >> e;
        capacity[s - 1][e - 1] = 1;
    }

    cout << Maximun_Flow(0, 1);

}