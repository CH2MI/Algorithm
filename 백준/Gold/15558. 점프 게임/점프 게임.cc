#include <bits/stdc++.h>
using namespace std;

int N, k;
array<string, 2> v;

int BFS() {
    queue<array<int, 3>> q;
    vector<array<int, 2>> visited(N);

    q.push({0, 0, 0});
    while (!q.empty()) {
        auto [cur_w, cur_h, time] = q.front(); q.pop();

        if (cur_w < 0) continue;
        if (cur_w >= N) return 1;
        if (v[cur_h][cur_w] == '0') continue;
        if (time > cur_w) continue;
        if (visited[cur_w][cur_h]) continue;

        visited[cur_w][cur_h] = 1;

        q.push({cur_w + 1, cur_h, time + 1});
        q.push({cur_w - 1, cur_h, time + 1});
        q.push({cur_w + k, !cur_h, time + 1});
    }

    return 0;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    cin >> N >> k >> v[0] >> v[1];
    cout << BFS();

}
