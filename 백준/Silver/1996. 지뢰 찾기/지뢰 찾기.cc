#include <bits/stdc++.h>
using namespace std;

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int N; cin >> N;
    vector<string> v(N);
    vector<vector<int>> board(N, vector<int>(N));
    for (auto& s : v) cin >> s;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (v[i][j] != '.') continue;
            for (int k = 0; k < 8; k++) {
                int x = i + dx[k];
                int y = j + dy[k];
                if (x < 0 || x >= N || y < 0 || y >= N) continue;
                if (v[x][y] != '.') board[i][j] += v[x][y] - '0';
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (v[i][j] != '.') cout << '*';
            else if (board[i][j] > 9) cout << 'M';
            else cout << (char)(board[i][j] + '0');
        }
        cout << '\n';
    }


}