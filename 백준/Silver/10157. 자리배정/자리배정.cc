#include <bits/stdc++.h>
using namespace std;

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int C, R, K;
    cin >> C >> R >> K;
    if (C * R < K) cout << 0;
    else {
        int cnt = 1;
        vector<vector<int>> visited(R, vector<int>(C));
        queue<array<int, 4>> q;
        q.push({1, 0, R - 1, 0});
        while (!q.empty()) {
            auto [cnt, k, r, c] = q.front();
            q.pop();

            if (cnt == K) {
                cout << c + 1 << ' ' << R - r;
                break;
            }

            visited[r][c] = 1;

            if (r + dr[k] < 0 || r + dr[k] >= R || c + dc[k] < 0 || c + dc[k] >= C) k = (k + 1) % 4;
            else if (visited[r + dr[k]][c + dc[k]]) k = (k + 1) % 4;


            q.push({cnt + 1, k, r + dr[k], c + dc[k]});
        }
    }

}
