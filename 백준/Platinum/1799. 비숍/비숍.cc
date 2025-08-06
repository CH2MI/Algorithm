#include <bits/stdc++.h>
using namespace std;

int N;
vector<vector<int>> v;

bool IsPossible(array<int, 2>& p) {
    if (v[p[0]][p[1]] == 0) return 0;

    int x = p[0];
    int y = p[1];
    while (--x > -1 && --y > -1) {
        if (v[x][y] == 2) return 0;
    }
    return 1;
}

int DFS(array<int, 2> p, int cnt) {
    if (p[0] >= N || p[1] >= N) return cnt;

    auto nxt = p;
    if (p[0] == N - 1) nxt[1] += 2;
    else nxt[0] += 2;

    if (nxt[0] >= N) nxt[0]--, nxt[1]++;

    int mx = 0;
    while (0 <= p[0] && p[1] < N) {
        if (IsPossible(p)) {
            v[p[0]][p[1]] = 2;
            mx = max(DFS(nxt, cnt + 1), mx);
            v[p[0]][p[1]] = 1;
        }
        p[0]--, p[1]++;
    }

    mx = max(DFS(nxt, cnt), mx);

    return mx;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    v.assign(N, vector<int>(N));
    for (auto& i : v)  for (auto& j : i) cin >> j;

    cout << DFS({0, 0}, 0) + DFS({1, 0}, 0);
}