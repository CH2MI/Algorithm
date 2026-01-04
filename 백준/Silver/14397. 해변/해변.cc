#include <bits/stdc++.h>
using namespace std;


int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    #ifdef LOCAL_DEBUG
        freopen("input.txt", "r", stdin);
    #endif

    int N, M; cin >> N >> M;
    vector<string> v(N);
    for (auto& s : v) cin >> s;

    int cnt = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M - 1; j++) {
            cnt += v[i][j] != v[i][j + 1];
        }
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N - 1; j++) {
            cnt += v[j][i] != v[j + 1][i];
        }
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N - 1; j++) {
            if (j % 2) {
                if (i == M - 1) continue;
                cnt += v[j][i] != v[j + 1][i + 1];
            }
            else {
                if (!i) continue;
                cnt += v[j][i] != v[j + 1][i - 1];
            }
        }
    }

    cout << cnt;


}
