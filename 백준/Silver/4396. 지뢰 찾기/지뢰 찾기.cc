#include <bits/stdc++.h>
using namespace std;

int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int N; cin >> N;
    vector<string> v1(N), v2(N);

    for (auto& s : v1) cin >> s;
    for (auto& s : v2) cin >> s;

    vector<vector<int>> v(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < 8; k++) {
                int x = i + dx[k], y = j + dy[k];
                if (x < 0 || x >= N || y < 0 || y >= N) continue;
                if (v1[x][y] == '*') v[i][j]++;
            }
        }
    }

    int f = true;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (v1[i][j] == '*' && v2[i][j] == 'x') f = false;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (f) {
                if (v2[i][j] == 'x') cout << v[i][j];
                else cout << '.';
            }
            else {
                if (v2[i][j] == 'x') {
                    if (v1[i][j] == '*') cout << '*';
                    else cout << v[i][j];
                }
                else cout << v1[i][j];
            }
        }
        cout << '\n';
    }

}
