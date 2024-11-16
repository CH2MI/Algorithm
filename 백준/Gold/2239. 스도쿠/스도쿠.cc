#include <iostream>
using namespace std;

int v[9][9];

bool is_vaild(int value, int x, int y) {
    for (int k = 0; k < 9; k++) {
        if (v[x][k] == value) return false;
        if (v[k][y] == value) return false;
    }

    while (x % 3) x--;
    while (y % 3) y--;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (v[x + i][y + j] == value) return false;

    return true;

}

bool back_tracking(int cnt, int index) {
    if (!cnt) {
        for (auto& i : v) {
            for (auto j : i) cout << j;
            cout << '\n';
        }
        return true;
    }

    while (true) {
        int i = index / 9, j = index % 9;
        if (v[i][j] == 0) break;
        index++;
    }

    int i = index / 9, j = index % 9;
    for (int l = 1; l <= 9; l++) {
        if (is_vaild(l, i, j)) {
            v[i][j] = l;
            if (back_tracking(cnt - 1, 9 * i + j + 1)) return true;
            v[i][j] = 0;
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int cnt = 0;

    for (auto& i : v) {
        for (int& j : i) {
            j = cin.get() - '0';
            if (!j) cnt++;
        }
        cin.ignore();
    }

    back_tracking(cnt, 0);

}