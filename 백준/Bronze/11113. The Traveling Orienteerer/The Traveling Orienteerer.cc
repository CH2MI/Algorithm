#include <bits/stdc++.h>
using namespace std;

double get_dist(array<double, 2>& a, array<double, 2>& b) {
    return sqrt((a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1]));
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N; cin >> N;
    vector<array<double, 2>> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i][0] >> v[i][1];
    }

    int T; cin >> T;
    while (T--) {
        int M; cin >> M;

        double sum = 0;
        int a; cin >> a;
        for (int i = 0; i < M - 1; i++) {
            int b; cin >> b;
            sum += get_dist(v[a], v[b]);
            a = b;
        }
        cout << (long long)round(sum) << '\n';
    }
}