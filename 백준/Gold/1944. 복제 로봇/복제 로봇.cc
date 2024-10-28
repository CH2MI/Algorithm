#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <map>
#define INF (int) 1e9
using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

int N, M;
vector<string> m;
map<pair<int, int>, int> v;
vector<vector<pair<int, int>>> adj;

void BFS(int sx, int sy) {
    int n = v[{sx, sy}];
    vector<vector<int>> visited(N, vector<int>(N));
    queue<tuple<int, int, int>> q;
    q.push({0, sx, sy});
    while (!q.empty()) {
        auto [cur_w, cur_x, cur_y] = q.front();
        q.pop();

        if (cur_x < 0 || cur_x >= N || cur_y < 0 || cur_y >= N) continue;
        if (m[cur_x][cur_y] == '1') continue;
        if (visited[cur_x][cur_y]) continue;

        visited[cur_x][cur_y] = 1;
        if (m[cur_x][cur_y] == 'S' || m[cur_x][cur_y] == 'K') {
            if (cur_w) {
                auto m = v[{cur_x, cur_y}];
                adj[n].push_back({m, cur_w});
            }
        }

        for (int i = 0; i < 4; i++) {
            int nxt_x = cur_x + dx[i];
            int nxt_y = cur_y + dy[i];
            int nxt_w = cur_w + 1;
            q.push({nxt_w, nxt_x, nxt_y});
        }
    }
}

int Prim() {
    vector<int> d(M + 1, INF);
    priority_queue<pair<int, int>> pq;
    pq.push({0, 0});
    int cnt = 0;

    while (!pq.empty()) {
        auto [cur_w, cur_n] = pq.top();
        cur_w = -cur_w;
        pq.pop();

        if (d[cur_n] != INF) continue;
        d[cur_n] = cur_w;
        if (++cnt == M + 1) break;

        for (auto& [nxt_n, nxt_w] : adj[cur_n]) {
            pq.push({-nxt_w, nxt_n});
        }
    }

    int sum = 0;
    for (auto i : d) {
        if (i == INF) return -1;
        sum += i;
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> M;
    m.assign(N, string());
    int vc = 1;

    for (int i = 0; i < N; i++) {
        cin >> m[i];

        for (int j = 0; j < N; j++) {
            if (m[i][j] == 'S') v.insert({{i, j}, 0});
            else if (m[i][j] == 'K') v.insert({{i, j}, vc++});
        }
    }
    adj.assign(M + 1, vector<pair<int, int>>());

    for (auto i : v) {
        BFS(i.first.first, i.first.second);
    }

    cout << Prim();
}