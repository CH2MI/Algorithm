#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    double W, H, x, y, x1, y1, x2, y2;
    cin >> W >> H >> x >> y >> x1 >> y1 >> x2 >> y2;

    double a = x - (y * (x1 - x)) / (y1 - y), b = x - (y * (x2 - x)) / (y2 - y);

    if (y1 > y && y2 > y) cout << 0;
    else if (a > W) cout << 0;
    else if (b < 0) cout << 0;
    else {
        a = max(a, 0.0);
        b = min(b, W);

        cout << fixed << setprecision(8) << (b - a) / W;
    }
}