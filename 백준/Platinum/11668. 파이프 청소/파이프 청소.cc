#include <bits/stdc++.h>
using namespace std;

typedef array<int, 2> point;

int CCW(point& a, point& b, point& c) {
    int ans = a[0] * b[1] + b[0] * c[1] + c[0] * a[1] - (b[0] * a[1] + c[0] * b[1] + a[0] * c[1]);
    if (ans > 0) return 1;
    if (ans < 0) return -1;
    return 0;
}

bool intersect(point& a, point& b, point& c, point& d) {
    int ab = CCW(a, b, c) * CCW(a, b, d);
    int cd = CCW(c, d, a) * CCW(c, d, b);
    if (!ab && !cd) {
        if (a > b) swap(a, b);
        if (c > d) swap(c, d);
        return a <= d && c <= b;
    }
    return ab <= 0 && cd <= 0;
}

vector<vector<int>> adj;
vector<int> visited;
int f = 0, cnt = 0;

void DFS(int pre, int cur) {
    if (pre == -1) visited[cur] = 0;
    else visited[cur] = visited[pre] + 1;

    for (int& nxt : adj[cur]) {
        if (nxt == pre) continue;
        if (visited[nxt] == -1) DFS(cur, nxt);
        else {
            // 변이 홀수 개인 사이클이 만들어진다.
            if ((visited[cur] - visited[nxt]) % 2 == 0) f = 1;
        }
    }
}


int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int w, p; cin >> w >> p;
    vector<point> source(w);
    for (auto& [x, y] : source) cin >> x >> y;

    vector<array<point, 2>> v(p);
    for (int i = 0; i < p; i++) {
        int s, x, y; cin >> s >> x >> y;
        v[i] = {source[s - 1], {x, y}};
    }


    adj.assign(p, vector<int>());
    for (int i = 0; i < p; i++) {
        for (int j = i + 1; j < p; j++) {
            if (v[i][0] == v[j][0]) continue;
            if (intersect(v[i][0], v[i][1], v[j][0], v[j][1])) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    visited.assign(p, -1);
    for (int i = 0; i < p; i++) {
        if (visited[i] == -1) DFS(-1, i);
    }
    cout << (f ? "impossible" : "possible");
}
