#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    double X, Y, D, T;
    cin >> X >> Y >> D >> T;

    cout << fixed;
    cout.precision(9);

    double dist = sqrt(pow(X, 2) + pow(Y, 2));

    // 1. 점프 효율이 좋지 않으면
    if (D / T <= 1.0) cout << dist;

    // 2. 점프 효율이 더 좋을 때
    else {
        long long jump = dist / D;
        double r = dist - (jump * D);

        if (jump == 0) {
            cout << min({r, 2 * T, abs(D - r) + T});
        }
        else {
            cout << jump * T + min({r, T, abs(D - r) + T});
        }
    }
}