#include <bits/stdc++.h>
using namespace std;

struct room {
    char type;
    int cost;
    vector<int> next;
};

vector<room> rooms;

int n;

int BFS() {
    queue<array<int, 2>> q; // 방위치, 소지금
    vector<int> visited(n, -1);
    q.push({0, 0});
    while (!q.empty()) {
        auto [cur_room, cur_cost] = q.front();
        q.pop();

        // 트롤이면 통행료 지불
        if (rooms[cur_room].type == 'T') {
            // 못지나가유
            if (cur_cost < rooms[cur_room].cost) continue;
            cur_cost -= rooms[cur_room].cost;
        }

        if (cur_room == n - 1) return 1;

        // 이미 더 적은 돈으로 와봤다면 다시 갈 필요 가 없죠
        if (cur_cost <= visited[cur_room]) continue;

        visited[cur_room] = cur_cost;

        // 레프리콘이면 돈 채워줍시다.
        if (rooms[cur_room].type == 'L') {
            cur_cost = max(cur_cost, rooms[cur_room].cost);
        }

        for (int& nxt_room : rooms[cur_room].next) {
            q.push({nxt_room, cur_cost});
        }
    }
    return 0;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    while (1) {
        cin >> n;
        if (!n) break;

        rooms.assign(n, room());
        for (int i = 0; i < n; i++) {
            cin >> rooms[i].type >> rooms[i].cost;

            while (1) {
                int m; cin >> m;
                if (!m) break;
                rooms[i].next.push_back(m - 1);
            }
        }

        if (BFS()) cout << "Yes\n";
        else cout << "No\n";
    }

}