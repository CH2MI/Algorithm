#include <bits/stdc++.h>
using namespace std;

int check(vector<string>& v) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 6; j++) {
            if (v[i][j] == 'X' && v[i][j] == v[i][j + 1] && v[i][j] == v[i][j + 2] && v[i][j] == v[i][j + 3] && v[i][j] == v[i][j + 4]) return 1;
            if (v[j][i] == 'X' && v[j][i] == v[j + 1][i] && v[j][i] == v[j + 2][i] && v[j][i] == v[j + 3][i] && v[j][i] == v[j + 4][i]) return 1;
        }
    }

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            if (v[i][j] == 'X' && v[i][j] == v[i + 1][j + 1] && v[i][j] == v[i + 2][j + 2] && v[i][j] == v[i + 3][j + 3] && v[i][j] == v[i + 4][j + 4]) return 1;
        }
    }

    for (int i = 0; i < 6; i++) {
        for (int j = 4; j < 10; j++) {
            if (v[i][j] == 'X' && v[i][j] == v[i + 1][j - 1] && v[i][j] == v[i + 2][j - 2] && v[i][j] == v[i + 3][j - 3] && v[i][j] == v[i + 4][j - 4]) return 1;
        }
    }

    return 0;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    vector<string> v(10);
    for (auto& s : v) cin >> s;

    int win = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (v[i][j] == '.') {
                v[i][j] = 'X';
                win |= check(v);
                v[i][j] = '.';
            }
        }
    }

    cout << win;
}
