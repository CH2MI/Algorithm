#include <bits/stdc++.h>
using namespace std;

int dx[3] = {0, -1, 0};
int dy[3] = {-1, 0, 1};

int N, M, D;
vector<vector<int>> v;

inline int GetDist(int ax, int ay, int bx, int by) {
    return abs(ax - bx) + abs(ay - by);
}

int cal(array<int, 3> p) {
    auto board = v;
    board.emplace_back(M);
    for (int i : p) board.back()[i] = 2;
    int cnt = 0;

    for (int i = N; i > 0; i--) {
        set<array<int, 2>> st;

        for (int j = 0; j < 3; j++) {
            vector<vector<int>> visited(i + 1, vector<int>(M));

            queue<array<int, 2>> q;
            q.push({i, p[j]});
            while (!q.empty()) {
                auto [x, y] = q.front(); q.pop();

                if (x < 0 || x > i || y < 0 || y >= M) continue;
                if (GetDist(i, p[j], x, y) > D) continue;
                if (visited[x][y]) continue;
                if (board[x][y] == 1) {
                    st.insert({x, y});
                    break;
                }

                visited[x][y] = 1;

                for (int k = 0; k < 3; k++)
                    q.push({x + dx[k], y + dy[k]});
            }
        }


        cnt += st.size();
        for (auto point : st)
            board[point[0]][point[1]] = 0;
        board.erase(board.begin() + i - 1);
    }

    return cnt;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> N >> M >> D;
    v.assign(N, vector<int>(M));
    for (auto& i : v) for (auto& j : i) cin >> j;

    int mx = 0;
    for (int i = 0; i < M; i++)
        for (int j = i + 1; j < M; j++)
            for (int k = j + 1; k < M; k++)
                mx = max(mx, cal({i, j, k}));

    cout << mx;
}