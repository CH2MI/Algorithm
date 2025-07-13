#include <bits/stdc++.h>
using namespace std;

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int N, M;
vector<string> v;

int cal() {
    int cnt = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (v[i][j] == '.') continue;
            for (int k = 0; k < 8; k++) {
                int x = i + dx[k], y = j + dy[k];
                if (x < 0 || x >= N || y < 0 || y >= M) continue;
                if (v[x][y] == 'o') cnt++;
            }
        }
    }

    return cnt / 2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
   v.assign(N, string());

    for (auto& i : v) cin >> i;

    int cnt = cal();

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (v[i][j] == 'o') continue;
            v[i][j] = 'o';
            cnt = max(cnt, cal());
            v[i][j] = '.';
        }
    }

    cout << cnt;

}