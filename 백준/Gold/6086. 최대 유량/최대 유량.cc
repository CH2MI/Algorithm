#include <bits/stdc++.h>
using namespace std;


vector<vector<int>> adj(52, vector<int>(52)), flow(adj);

int Maximum_Flow() {
    int total_flow = 0;

    while (1) {
        vector<int> parent(52, -1);
        queue<int> q;
        q.push(0);
        parent[0] = 0;

        while (!q.empty() && parent[25] == -1) {
            int cur = q.front(); q.pop();

            for (int nxt = 0; nxt < 52; nxt++) {
                if (adj[cur][nxt] - flow[cur][nxt] > 0 && parent[nxt] == -1) {
                    q.push(nxt);
                    parent[nxt] = cur;
                }
            }
        }

        if (parent[25] == -1)
            break;

        int amount = INT_MAX;
        for (int cur = 25; cur; cur = parent[cur]) {
            amount = min(amount, adj[parent[cur]][cur] - flow[parent[cur]][cur]);
        }

        for (int cur = 25; cur; cur = parent[cur]) {
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

    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        char s, e; int w;
        cin >> s >> e >> w;

        if (s > 'Z') s -= 'a' - 26;
        else s -= 'A';

        if (e > 'Z') e -= 'a' - 26;
        else e -= 'A';

        adj[s][e] += w;
        adj[e][s] += w;
    }

    cout << Maximum_Flow();

}