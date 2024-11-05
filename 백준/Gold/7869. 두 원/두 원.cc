#include <iostream>
#include <cmath>
#define _USE_MATH_DEFINES
using namespace std;

double GetDist(double v[]) {
    return sqrt(pow(v[3] - v[0], 2) + pow(v[4] - v[1], 2));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    double v[6];
    for (int i = 0; i < 6; i++) cin >> v[i];

    double d = GetDist(v);
    cout << fixed;
    cout.precision(3);

    // 두 원이 겹치지 않을 때
    if (v[2] + v[5] <= d) cout << 0.0;

    // 포함 관계일 대
    else if (abs(v[2] - v[5]) >= d) cout << round(pow(min(v[2], v[5]), 2) * M_PI * 1000) / 1000;

    else {
        double cos_a = (v[2] * v[2] + d * d - v[5] * v[5]) / (2 * v[2] * d);
        double cos_b = (v[5] * v[5] + d * d - v[2] * v[2]) / (2 * v[5] * d);
        double theta_a = 2 * acos(cos_a), theta_b = 2 * acos(cos_b);
        double tri_a = v[2] * v[2] * sin(theta_a) / 2, tri_b = v[5] * v[5] * sin(theta_b) / 2;
        double sector = (1.0 / 2.0 * v[2] * v[2] * theta_a) + (1.0 / 2.0 * v[5] * v[5] * theta_b);
        cout << round((sector - tri_a - tri_b) * 1000) / 1000;
    }
}