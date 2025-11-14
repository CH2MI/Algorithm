#include <bits/stdc++.h>
using namespace std;

constexpr int INF = (int)1e9;

int N, M;
vector<vector<int>> capacity, flow, pay;

array<int, 2> mcmf(int source, int sink) {
    int total_count = 0, total_pay = 0;

    while (1) {
        vector<int> parent(N + M + 2, -1);
        vector<int> dist(N + M + 2, INF);
        vector<int> is_queue(N + M + 2);

        queue<int> q;
        q.push(source);
        dist[source] = 0;
        parent[source] = source;

        while (!q.empty()) {
            int cur = q.front(); q.pop();
            is_queue[cur] = 0;

            for (int nxt = 0; nxt < N + M + 2; nxt++) {
                if (capacity[cur][nxt] - flow[cur][nxt] > 0 && dist[nxt] > dist[cur] + pay[cur][nxt]) {
                    dist[nxt] = dist[cur] + pay[cur][nxt];
                    parent[nxt] = cur;

                    if (!is_queue[nxt]) {
                        is_queue[nxt] = 1;
                        q.push(nxt);
                    }
                }
            }
        }
        if (parent[sink] == -1) break;

        int amount = INF;
        for (int cur = sink; cur != source; cur = parent[cur]) {
            amount = min(amount, capacity[parent[cur]][cur] - flow[parent[cur]][cur]);
        }

        for (int cur = sink; cur != source; cur = parent[cur]) {
            total_pay += amount * pay[parent[cur]][cur];

            flow[parent[cur]][cur] += amount;
            flow[cur][parent[cur]] -= amount;
        }

        total_count++;
    }

    return {total_count, total_pay};
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
 
#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    cin >> N >> M;
    capacity.assign(N + M + 2, vector<int>(N + M + 2));
    flow.assign(N + M + 2, vector<int>(N + M + 2));
    pay.assign(N + M + 2, vector<int>(N + M + 2));

    for (int s = 1; s <= N; s++) {
        int n; cin >> n;
        for (int i = 0; i < n; i++) {
            int e, w; cin >> e >> w;
            capacity[s][e + N] = 1;

            pay[s][e + N] = w;
            pay[e + N][s] = -w;
        }
    }
    for (int i = 0; i < N; i++) capacity[0][i + 1] = 1;
    for (int i = 0; i < M; i++) capacity[i + N + 1][N + M + 1] = 1;

    auto [total_count, total_pay] = mcmf(0, N + M + 1);
    cout << total_count << '\n' << total_pay;

}