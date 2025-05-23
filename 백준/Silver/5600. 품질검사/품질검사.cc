#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int a, b, c; cin >> a >> b >> c;
    vector<int> v(a + b + c, 2);
    int N; cin >> N;

    vector<array<int, 4>> result(N);
    for (int i = 0; i < N; i++) for (int j = 0; j < 4; j++) cin >> result[i][j];

    for (int i = 0; i < N; i++) {
        if (!result[i][3]) continue;
        for (int j = 0; j < 3; j++) v[result[i][j] - 1] = 1;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (result[i][3]) continue;

            int cnt = 0;
            for (int k = 0; k < 3; k++) cnt += v[result[i][k] - 1] == 1;

            if (cnt == 2) {
                if (v[result[i][0] - 1] == 2) v[result[i][0] - 1] = 0;
                if (v[result[i][1] - 1] == 2) v[result[i][1] - 1] = 0;
                if (v[result[i][2] - 1] == 2) v[result[i][2] - 1] = 0;
            }
        }
    }

    for (int i : v) cout << i << '\n';

}