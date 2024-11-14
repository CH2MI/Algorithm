#include <iostream>
#include <vector>
using namespace std;

int N;

void move_up(vector<vector<int>>& board) {
    vector<vector<bool>> iscombined(N, vector<bool>(N));
    for (int j = 0; j < N; j++) {
        for (int i = 0; i < N; i++) {
            if (!board[i][j]) continue;
            int k = i;

            while (k - 1 >= 0) {
                if (!board[k - 1][j]) board[k - 1][j] = board[k][j];
                else if (board[k - 1][j] == board[k][j] && !iscombined[k - 1][j] && !iscombined[k][j]) {
                    board[k - 1][j] += board[k][j];
                    iscombined[k - 1][j] = 1;
                }
                else {
                    break;
                }
                board[k--][j] = 0;
            }
        }
    }
}

void move_down(vector<vector<int>>& board) {
    vector<vector<bool>> iscombined(N, vector<bool>(N));
    for (int j = 0; j < N; j++) {
        for (int i = N - 1; i >= 0; i--) {
            if (!board[i][j]) continue;
            int k = i;

            while (k + 1 < N) {
                if (!board[k + 1][j]) board[k + 1][j] = board[k][j];
                else if (board[k + 1][j] == board[k][j] && !iscombined[k + 1][j] && !iscombined[k][j]) {
                    board[k + 1][j] += board[k][j];
                    iscombined[k + 1][j] = 1;
                }
                else {
                    break;
                }
                board[k++][j] = 0;
            }
        }
    }
}

void move_left(vector<vector<int>>& board) {
    vector<vector<bool>> iscombined(N, vector<bool>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!board[i][j]) continue;
            int k = j;

            while (k - 1 >= 0) {
                if (!board[i][k - 1]) board[i][k - 1] = board[i][k];
                else if (board[i][k - 1] == board[i][k] && !iscombined[i][k - 1] && !iscombined[i][k]) {
                    board[i][k - 1] += board[i][k];
                    iscombined[i][k - 1] = 1;
                }
                else {
                    break;
                }
                board[i][k--] = 0;
            }
        }
    }
}

void move_right(vector<vector<int>>& board) {
    vector<vector<bool>> iscombined(N, vector<bool>(N));
    for (int i = 0; i < N; i++) {
        for (int j = N - 1; j >= 0; j--) {
            if (!board[i][j]) continue;
            int k = j;

            while (k + 1 < N) {
                if (!board[i][k + 1]) board[i][k + 1] = board[i][k];
                else if (board[i][k + 1] == board[i][k] && !iscombined[i][k + 1] && !iscombined[i][k]) {
                    board[i][k + 1] += board[i][k];
                    iscombined[i][k + 1] = 1;
                }
                else {
                    break;
                }
                board[i][k++] = 0;
            }
        }
    }
}

int max(vector<vector<int>>& board) {
    int mx = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            mx = max(mx, board[i][j]);
        }
    }
    return mx;
}

int backtracking(vector<vector<int>> board, int cnt, int d) {
    if (d == 0) move_up(board);
    else if (d == 1) move_right(board);
    else if (d == 2) move_down(board);
    else move_left(board);

    if (cnt == 5) return max(board);

    int mx = 0;
    for (int i = 0; i < 4; i++) {
        mx = max(backtracking(board, cnt + 1, i), mx);
    }
    return mx;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    vector<vector<int>> board(N, vector<int>(N));
    for (auto& i : board) for (auto& j : i) cin >> j;

    int mx = 0;
    for (int i = 0; i < 4; i++) {
        mx = max(backtracking(board, 1, i), mx);
    }
    cout << mx;
}