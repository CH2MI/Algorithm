#include <bits/stdc++.h>
using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int N, M;
vector<string> v;
vector<vector<int>> visited;

int DFS(int x, int y, int num) {
    visited[x][y] = num;

    int sum = 0;
    for (int k = 0; k < 4; k++) {
        int i = x + dx[k], j = y + dy[k];
        if (i < 0 || i >= N || j < 0 || j >= M) continue;
        if (v[i][j] == '1') continue;
        if (visited[i][j] != -1) continue;
        sum += DFS(i, j, num);
    }

    return sum + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    v.assign(N, string());

    for (auto& i : v) cin >> i;

    visited.assign(N, vector<int>(M, -1));

    int num = 0;
    vector<int> counts;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (v[i][j] == '1') continue;
            if (visited[i][j] != -1) continue;
            int cnt = DFS(i, j, num++);
            counts.push_back(cnt);
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (v[i][j] == '0') cout << 0;
            else {
                set<int> s;
                for (int k = 0; k < 4; k++) {
                    int x = i + dx[k], y = j + dy[k];
                    if (x < 0 || x >= N || y < 0 || y >= M) continue;
                    if (visited[x][y] == -1) continue;
                    s.insert(visited[x][y]);
                }

                int sum = 1;
                for (auto i : s) sum += counts[i];
                cout << sum % 10;
            }
        }
        cout << '\n';
    }
}