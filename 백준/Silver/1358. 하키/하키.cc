#include <bits/stdc++.h>
using namespace std;

int W, H, X, Y;



int isIn(int x, int y) {
    if (x >= X && x <= X + W && y >= Y && y <= Y + H) return 1;

    int dist = (x - X) * (x - X) + (y - (Y + H / 2)) * (y - (Y + H / 2));
    if (dist <= (H / 2) * (H / 2)) return 1;

    dist = (x - (X + W)) * (x - (X + W)) + (y - (Y + H / 2)) * (y - (Y + H / 2));
    if (dist <= (H / 2) * (H / 2)) return 1;
    return 0;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int P;
    cin >> W >> H >> X >> Y >> P;

    int cnt = 0;

    for (int i = 0; i < P; i++) {
        int x, y; cin >> x >> y;
        cnt += isIn(x, y) == 1;
    }
    cout << cnt;
}
