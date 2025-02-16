#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (1) {
        int N; cin >> N;
        if (!N) break;

        vector<tuple<int, string, double>> v(N);
        for (int i = 0; i < N; i++) {
            string a; double b;
            cin >> a >> b;
            v[i] = {i, a, b};
        }

        sort(v.begin(), v.end(), [](auto& a, auto& b) {
            auto [a1, a2, a3] = a;
            auto [b1, b2, b3] = b;
            if (a3 == b3) return a1 < b1;
            return a3 > b3;
        });

        double mx = get<2>(v[0]);
        for (auto [a, b, c] : v) {
            if (mx == c) cout << b << ' ';
        }
        cout << '\n';
    }
}
