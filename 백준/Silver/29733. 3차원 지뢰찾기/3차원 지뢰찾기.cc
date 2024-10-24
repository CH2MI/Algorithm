#include <iostream>
#include <vector>
using namespace std;

int dr[26] = {-1, -1, -1, 0, 0, 0, 1, 1, 1, -1, -1, -1, 0, 0, 1, 1, 1, -1, -1, -1, 0, 0, 0, 1, 1, 1};
int dc[26] = {-1, 0, 1, -1, 0, 1, -1, 0, 1, -1, 0, 1, -1, 1, -1, 0, 1, -1, 0, 1, -1, 0, 1, -1, 0, 1};
int dh[26] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1};

int R, C, H;
vector<vector<string>> board;

int bomb_count(int h, int r, int c) {
    int count = 0;
    for (int i = 0; i < 26; i++) {
        int x = h + dh[i];
        int y = r + dr[i];
        int z = c + dc[i];
        if (x < 0 || x >= H || y < 0 || y >= R || z < 0 || z >= C) continue;
        if (board[x][y][z] == '*') count++;
    }
    return count % 10;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> R >> C >> H;
    board.assign(H, vector<string>(R, string()));
    for (int h = 0; h < H; h++) {
        for (int r = 0; r < R; r++) {
            cin >> board[h][r];
        }
    }

    for (int h = 0; h < H; h++) {
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                if (board[h][r][c] == '.') board[h][r][c] = bomb_count(h, r, c) + '0';
            }
        }
    }

    for (const auto& i : board) {
        for (const auto& j : i) cout << j << '\n';
    }
}
