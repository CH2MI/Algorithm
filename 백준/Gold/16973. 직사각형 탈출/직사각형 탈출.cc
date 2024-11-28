#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int N, M, W, H, sx, sy, fx, fy;
vector<vector<int>> board;

bool ismovalve(int d, int x, int y) {
    // 위
    if (d == 0) {
        if (x - 1 < 0) return false;
        for (int i = 0; i < W; i++) {
            if (board[x - 1][y + i]) return false;
        }
    }
    // 오른쪽
    else if (d == 1) {
        if (y + W >= M) return false;
        for (int i = 0; i < H; i++) {
            if (board[x + i][y + W]) return false;
        }
    }
    // 아래
    else if (d == 2) {
        if (x + H >= N) return false;
        for (int i = 0; i < W; i++) {
            if (board[x + H][y + i]) return false;
        }
    }
    else {
        if (y - 1 < 0) return false;
        for (int i = 0; i < H; i++) {
            if (board[x + i][y - 1]) return false;
        }
    }
    return true;
}

int BFS() {
    queue<tuple<int, int, int>> q;
    vector<vector<int>> visited(N, vector<int>(M));
    q.push({sx - 1, sy - 1, 0});
    while (!q.empty()) {
        auto[x, y, cnt] = q.front();
        q.pop();

        if (x == fx - 1 && y == fy - 1) return cnt;

        for (int k = 0; k < 4; k++) {
            if (ismovalve(k, x, y)) {
                int i = x + dx[k];
                int j = y + dy[k];
                if (!visited[i][j]) {
                    visited[i][j] = 1;
                    q.push({i, j, cnt + 1});
                }
            }
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    board.assign(N, vector<int>(M));
    for (auto& i : board) for (int& j : i) cin >> j;
    cin >> H >> W >> sx >> sy >> fx >> fy;

    cout << BFS();
}