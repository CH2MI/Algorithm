#include <bits/stdc++.h>
using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int N;
vector<vector<int>> board;
deque<array<int, 2>> snake;
vector<pair<int, char>> rotates;

int simulation() {
    int cur_x = 0, cur_y = 0;
    int turn = 1;
    int d = 1;
    snake.push_back({0, 0});
    auto r = rotates.begin();

    while (1) {
        int nxt_x = cur_x + dx[d], nxt_y = cur_y + dy[d];
        if (nxt_x < 0 || nxt_x >= N || nxt_y < 0 || nxt_y >= N) return turn;

        snake.push_front({nxt_x, nxt_y});

        for (auto itr = snake.begin() + 1; itr != snake.end(); itr++) {
            if (*snake.begin() == *itr) return turn;
        }

        if (board[nxt_x][nxt_y] != 1) snake.pop_back();
        else board[nxt_x][nxt_y] = 0;

        if (r->first == turn) {
            if (r->second == 'L') d = (d - 1 + 4) % 4;
            else d = (d + 1) % 4;
            r++;
        }
        cur_x = nxt_x, cur_y = nxt_y;
        ++turn;
    }
}


int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    cin >> N;
    board.assign(N, vector<int>(N));

    int K; cin >> K;
    for (int i = 0; i < K; i++) {
        int x, y; cin >> x >> y;
        board[x - 1][y - 1] = 1;
    }

    int L; cin >> L;
    rotates.assign(L, pair<int, char>());
    for (auto& [x, c] : rotates) cin >> x >> c;

    cout << simulation();

}