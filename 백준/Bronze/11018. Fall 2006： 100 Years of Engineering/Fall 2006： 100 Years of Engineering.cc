#include <bits/stdc++.h>
using namespace std;

void solve(int cnt) {
    int N; double M;
    cin >> N >> M;

    vector<array<double, 3>> data(N);
    double w = M, v = 0;
    for (int i = 0; i < N; i++) {
        double m, t, f; cin >> m >> t >> f;
        data[i] = {m, t, f};
        w += m;
    }
    double dist = 0;
    for (int i = 0; i < N; i++) {
        double a = data[i][2] / w - 9.81;
        dist += v * data[i][1] + 0.5 * a * data[i][1] * data[i][1];
        v += a * data[i][1];
        w -= data[i][0];
    }
    cout << fixed;
    cout.precision(2);
    cout << "Data Set " << cnt << ":\n";
    cout << round(dist * 100) / 100 <<'\n';
    cout << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T; cin >> T;
    for (int i = 1; i <= T; i++) {
        solve(i);
    }
}