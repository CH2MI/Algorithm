#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
using namespace std;

int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};

queue<tuple<int, vector<vector<int>>, vector<vector<int>>>> q;

void move_fish(vector<vector<int>>& map, vector<vector<int>>& direction) {
    vector<vector<bool>> is_moved(4, vector<bool>(4));

    for (int k = 0; k < 16; k++) {
        int mnx = -1, mny = -1, mn = 17;

        // 움직일 수 있는 가장 작은 물고기를 찾는다.
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (map[i][j] < 1) continue;
                if (is_moved[i][j]) continue;
                if (mn > map[i][j]) mnx = i, mny = j, mn = map[i][j];
            }
        }

        // 더 이상 움직일 물고기가 없다.
        if (mn == 17) break;

        bool f = false;

        // 상어가 움직일 수 있는 경로를 찾는다.
        for (int i = 0; i < 8; i++) {
            int d = (direction[mnx][mny] + i) % 8;
            int nx = mnx + dx[d];
            int ny = mny + dy[d];


            // 공간의 경계를 넘는다.
            if (nx < 0 || nx > 3 || ny < 0 || ny > 3) continue;
            // 상어
            if (!map[nx][ny]) continue;

            // 이동할 수 있다.
            swap(map[mnx][mny], map[nx][ny]); swap(direction[mnx][mny], direction[nx][ny]); swap(is_moved[mnx][mny], is_moved[nx][ny]);
            is_moved[nx][ny] = 1;
            direction[nx][ny] = d;
            f = true;
            break;
        }
        if (!f) direction[mnx][mny] = (direction[mnx][mny] + 7) % 8;
    }
}

void eat_fish(vector<vector<int>>& map, vector<vector<int>>& direction, int sum) {
    int sx, sy;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (!map[i][j]) sx = i, sy = j;

    // 먹을 물고기 고르기
    for (int k = 0; k < 4; k++) {
        int d = direction[sx][sy];
        int i = sx + dx[d] * (k + 1);
        int j = sy + dy[d] * (k + 1);

        if (i < 0 || i > 3 || j < 0 || j > 3) break;
        if (map[i][j] == -1) continue;

        // 시간선을 분리한다.
        vector<vector<int>> m(map);

        int t = m[i][j];
        m[i][j] = 0; m[sx][sy] = -1;

        q.push({sum + t, m, direction});
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    vector<vector<int>> map(4, vector<int>(4)), direction(map);

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            cin >> map[i][j] >> direction[i][j], --direction[i][j];

    int sum = map[0][0];
    map[0][0] = 0;

    q.push({sum, map, direction});

    while (!q.empty()) {
        auto[s, m, d] = q.front(); q.pop();

        sum = max(sum, s);

        // 물고기 이동
        move_fish(m, d);

        // 잡아먹기
        eat_fish(m, d, s);
    }

    cout << sum << '\n';
}