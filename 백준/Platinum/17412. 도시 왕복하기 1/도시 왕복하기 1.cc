#include <bits/stdc++.h>
using namespace std;

int N;

vector<vector<int>> capacity, flow;

int Maximun_Flow(int source, int sink) {

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
        int amount = INT_MAX;

        for (int cur = sink; cur != source; cur = parent[cur]) {
            amount = min(amount, capacity[parent[cur]][cur] - flow[parent[cur]][cur]);
        }

        for (int cur = sink; cur != source; cur = parent[cur]) {
            flow[parent[cur]][cur] += amount;
            flow[cur][parent[cur]] -= amount;
        }

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