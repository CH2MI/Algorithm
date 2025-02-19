#include <bits/stdc++.h>
using namespace std;

int Rook(int x, int y) {
    int a[2][2] = {{0, 1}, {1, 0}};
    return ((x / 2) ^ (y / 2)) * 2 + a[x % 2][y % 2];
}

int Bishop(int x, int y) {
    return min(x, y);
}

int King(int x, int y) {
    int a[2][2] = {{0, 1}, {1, 2}};
    int b[2][2] = {{0, 1}, {3, 2}};
    int c[2][2] = {{0, 3}, {1, 2}};

    if (x / 2 == y / 2) return a[x % 2][y % 2];
    if (x / 2 < y / 2) return b[x % 2][y % 2];
    return c[x % 2][y % 2];
}

int Knight(int x, int y) {
    int a[3][3] = {{0, 0, 0}, {0, 0, 1}, {0, 1, 1}};
    int b[3][3] = {{0, 0, 0}, {1, 1, 1}, {1, 2, 2}};
    int c[3][3] = {{0, 1, 1}, {0, 1, 2}, {0, 1, 2}};
    int d[3][3] = {{0, 0, 0}, {1, 1, 1}, {2, 2, 2}};
    int e[3][3] = {{0, 1, 2}, {0, 1, 2}, {0, 1, 2}};

    if (x / 3 == y / 3) return a[x % 3][y % 3];
    if (abs(x / 3 - y / 3) == 1) {
        if (x / 3 < y / 3) return b[x % 3][y % 3];
        return c[x % 3][y % 3];
    }
    if (x / 3 < y / 3) return d[x % 3][y % 3];
    return e[x % 3][y % 3];
}

int Palace(int x, int y) {
    int a[3][3] = {{0, 1, 2}, {1, 2, 0}, {2, 0, 1}};
    return ((x / 3) ^ (y / 3)) * 3 + a[x % 3][y % 3];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    int sum = 0;

    for (int i = 0; i < N; i++) {
        int x, y; char z;
        cin >> x >> y >> z;
        if (z == 'R') sum ^= Rook(x, y);
        else if (z == 'B') sum ^= Bishop(x, y);
        else if (z == 'K') sum ^= King(x, y);
        else if (z == 'N') sum ^= Knight(x, y);
        else sum ^= Palace(x, y);
    }


    if (sum) cout << "koosaga";
    else cout << "cubelover";
}