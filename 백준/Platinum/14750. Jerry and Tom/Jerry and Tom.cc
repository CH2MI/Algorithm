#include <bits/stdc++.h>
using namespace std;

typedef array<long long, 2> point;

int CCW(point& a, point& b, point& c) {
    long long ans = a[0] * b[1] + b[0] * c[1] + c[0] * a[1] - (b[0] * a[1] + c[0] * b[1] + a[0] * c[1]);
    if (ans > 0) return 1;
    if (ans < 0) return -1;
    return 0;
}

int intersect(point a, point b, point c, point d) {
    int ab = CCW(a, b, c) * CCW(a, b, d);
    int cd = CCW(c, d, a) * CCW(c, d, b);

    if (!ab && !cd) {
        if (a > b) swap(a, b);
        if (c > d) swap(c, d);
        return a <= d && c <= b;
    }
    return ab <= 0 && cd <= 0;
}

int N, h, m;
vector<vector<int>> adj, capacity, flow;

int bfs(int source, int sink) {
    vector<int> parent(N, -1);
    parent[source] = source;

    queue<int> q; q.push(source);

    while (!q.empty() && parent[sink] == -1) {
        int cur = q.front(); q.pop();

        for (int nxt : adj[cur]) {
            if (capacity[cur][nxt] - flow[cur][nxt] > 0 && parent[nxt] == -1) {
                parent[nxt] = cur;
                q.push(nxt);
            }
        }
    }

    if (parent[sink] == -1) return 0;

    for (int cur = sink; cur != source; cur = parent[cur]) {
        flow[parent[cur]][cur] += 1;
        flow[cur][parent[cur]] -= 1;
    }

    return 1;
}

int mf(int source, int sink) {
    for (int i = 0; i < m; i++) {
        if (!bfs(source, sink)) return 0;
    }
    return 1;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int n, k; cin >> n >> k >> h >> m;

    vector<array<point, 2>> lines(n);
    point pre; cin >> pre[0] >> pre[1];

    for (int i = 1; i < n; i++) {
        point p; cin >> p[0] >> p[1];
        lines[i - 1] = {pre, p};
        pre = p;
    }
    lines.back() = {pre, lines.front()[0]};

    vector<point> holes(h);
    for (auto& [x, y] : holes) cin >> x >> y;
    vector<point> mice(m);
    for (auto& [x, y] : mice) cin >> x >> y;

    N = h + m + 2;
    adj.assign(N, vector<int>());
    capacity.assign(N, vector<int>(N));
    flow.assign(N, vector<int>(N));

    for (int i = 0; i < h; i++) {
        int sum = 0;
        for (auto& [p1, p2] : lines) {
            sum += intersect(p1, p2, holes[i], holes[i]);
        }

        for (int j = 0; j < m; j++) {
            int cnt = 0;
            for (auto& [p1, p2] : lines) {
                cnt += intersect(p1, p2, mice[j], holes[i]);
            }

            if (cnt == sum) {
                adj[j + 1].push_back(i + m + 1);
                adj[i + m + 1].push_back(j + 1);
                capacity[j + 1][i + m + 1] = 1;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        adj[0].push_back(i + 1);
        adj[i + 1].push_back(0);
        capacity[0][i + 1] = 1;
    }
    for (int i = 0; i < h; i++) {
        adj[i + m + 1].push_back(N - 1);
        adj[N - 1].push_back(i + m + 1);
        capacity[i + m + 1][N - 1] = k;
    }

    if (mf(0, N - 1)) cout << "Possible";
    else cout << "Impossible";
}

