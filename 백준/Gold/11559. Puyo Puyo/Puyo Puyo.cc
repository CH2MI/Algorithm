#include <bits/stdc++.h>
using namespace std;

constexpr int N = 12;
constexpr int M = 6;

char type[5] = {'R', 'G', 'B', 'P', 'Y'};
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

vector<string> v;
vector<vector<int>> visited;

int DFS1(int x, int y, char target) {
    if (visited[x][y]) return 0;
    visited[x][y] = 1;

    if (v[x][y] != target) return 0;

    int cnt = 0;
    for (int k = 0; k < 4; k++) {
        int i = x + dx[k], j = y + dy[k];
        if (i < 0 || i >= N || j < 0 || j >= M) continue;
        cnt += DFS1(i, j, target);
    }

    return cnt + 1;
}

void DFS2(int x, int y, char target) {
    if (v[x][y] != target) return;

    v[x][y] = '.';

    for (int k = 0; k < 4; k++) {
        int i = x + dx[k], j = y + dy[k];
        if (i < 0 || i >= N || j < 0 || j >= M) continue;
        DFS2(i, j, target);
    }
}

int simulation() {

    // chain 되는지 확인
    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (v[i][j] == '.') continue;
            visited.assign(N, vector<int>(M));

            if (DFS1(i, j, v[i][j]) > 3) {
                // 체인되면 지우기
                DFS2(i, j, v[i][j]);
                ans = 1;
            }
        }
    }

    for (int i = N - 2; i >= 0; i--) {
        for (int j = 0; j < M; j++) {
            int k = i;
            while (k < N - 1 && v[k][j] != '.' && v[k + 1][j] == '.') {
                v[k + 1][j] = v[k][j];
                v[k][j] = '.';
                k++;
            }
        }
    }

    return ans;
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    v.assign(N, string());
    for (auto& s : v) cin >> s;

    int cnt = 0;

    while (simulation()) cnt++;

    cout << cnt;

}