#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    #ifdef LOCAL_DEBUG
        freopen("input.txt", "r", stdin);
    #endif

    int N; cin >> N;
    vector<array<int, 5>> a(N);
    vector<array<int, 2>> v(N);
    for (int i = 0; i < N; i++) {
        for (int& j : a[i]) cin >> j;

        int mx = 0;
        for (int j = 0; j < 5; j++) {
            for (int k = j + 1; k < 5; k++) {
                for (int l = k + 1; l < 5; l++) {
                    mx = max(mx, (a[i][j] + a[i][k] + a[i][l]) % 10);
                }
            }
        }
        v[i] = {-mx, -i};
    }

    sort(v.begin(), v.end());
    cout << -v.front()[1] + 1;

}
