#include <iostream>
#include <vector>
using namespace std;

int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};

int N, M; 
vector<string> board;
vector<vector<char>> make;

void make_board() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (make[i][j] == 'F') {
                for (int k = 0; k < 8; k++) {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if (x < 0 || x >= N || y < 0 || y >= M) continue;
                    if (make[x][y] == 'F') continue;
                    make[x][y]++;
                }
            }
        }
    }
}

bool check() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] != make[i][j]) return false;
            
            if (make[i][j] == 'F') {
                bool f = true;
                for (int k = 0; k < 8; k++) {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if (x < 0 || x >= N || y < 0 || y >= M) continue;
                    if (make[x][y] != 'F') {
                        f = false;
                        break;
                    }
                }
                if (f) return false;
            }
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int T; cin >> T;

    while (T--) {
        cin >> N >> M;
        board.assign(N, string());
        make.assign(N, vector<char>(M, '0'));
        
        for (int i = 0; i < N; i++) {
            cin >> board[i];

            for (int j = 0; j < M; j++) {
                if (board[i][j] == 'F') make[i][j] = 'F';
            }
        }

        make_board();
        if (check()) cout << "Well done Clark!\n";
        else cout << "Please sweep the mine again!\n";
    }
}
