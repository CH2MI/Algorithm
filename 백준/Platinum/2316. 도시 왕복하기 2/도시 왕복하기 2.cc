#include <bits/stdc++.h>
using namespace std;

int N;
vector<vector<int>> capacity, flow;

int mf(int source, int sink) {
    int total_flow = 0;

    while (1) {
        vector<int> parent(N, -1);
        queue<int> q;
        q.push(source);
        parent[source] = source;

        while (!q.empty() && parent[sink] == -1) {
            int cur = q.front(); q.pop();

            for (int nxt = 0; nxt < N; nxt++) {
                if (capacity[cur][nxt] - flow[cur][nxt] > 0 && parent[nxt] == -1) {
                    parent[nxt] = cur;
                    q.push(nxt);
                }
            }
        }

        if (parent[sink] == -1) break;

        for (int cur = sink; cur != source; cur = parent[cur]) {
            flow[parent[cur]][cur] += 1;
            flow[cur][parent[cur]] -= 1;
        }

        total_flow++;
    }

    return total_flow;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int n, P; cin >> n >> P;
    N = n * 2;

    capacity.assign(N, vector<int>(N));
    flow.assign(N, vector<int>(N));

    for (int i = 0; i < n; i++) {
        capacity[i * 2][i * 2 + 1] = 1;
    }

    for (int i = 0; i < P; i++) {
        int s, e; cin >> s >> e;

        capacity[(s - 1) * 2 + 1][(e - 1) * 2] = 1;
        capacity[(e - 1) * 2 + 1][(s - 1) * 2] = 1;
    }

    cout << mf(1, 2);
}
